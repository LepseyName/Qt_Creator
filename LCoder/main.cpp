#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <QFile>
#define NUMBER_SHIFR 4

int level_coder = 3 ;
bool is_coder = true, is_file= false;

void set_coder(bool i){
    is_coder = i;
}
void coder(QFile &input, QFile &output, QString KEY){
    long size = input.size(), b=0;
    while( input.isReadable() ){
        char * K = new char; b++;
        int len = KEY.length();
        if (input.getChar(K)){
            while(len){
                QChar *key = new QChar[NUMBER_SHIFR];
                for( int i = len - NUMBER_SHIFR, j=0; i< len; i++, j++) key[j] = KEY[i];
                K = shifr(K, key, (int) size%(b), is_coder);
                delete[] key;
                len-=NUMBER_SHIFR;
            }
            output.putChar(*K);
        }
        else {break;}
        delete K;
    }

}
char* shifr(char *ch, QChar* KEY, int p_z, bool is_coder ){
    ushort a = KEY[0].unicode(),
           b = KEY[1].unicode(),
           c = KEY[2].unicode(),
           d = KEY[3].unicode();

    int gamma =  p_z*(a + b*d  + d*a ) - a*b - c*d;
    int sm =(int)(p_z*(11.0/255.0) + 5);																			//Çàäàåì ñìåùåíèå è ñìåùàåì(ðàíäîìèçèðóåì) ãàììó
    gamma = (gamma>>sm) | (gamma<<sm);
    gamma = (char)(gamma ) + (char)(gamma>>24) - (char)(gamma>>16) + (char)(gamma>>8) ;						//Ïàêóåì ãàììó â char ïîïóòíî ðàíäîìèçèðóåì

    if(is_coder) *ch += gamma;																					//Íàêëàäûâàåì èëè ñíèìàåì ãàììó
    else  	     *ch -= gamma;

    return ch;
}

QString coder(QString text, QString KEY){
    int a = KEY.length();
    if (a%NUMBER_SHIFR!=0)return "Код должен быть кратен "+QString::number(NUMBER_SHIFR);
    while( a ){
        QChar * Kstr = new QChar[NUMBER_SHIFR];
        for( int i = a - NUMBER_SHIFR, j=0; i< a; i++, j++) Kstr[j] = KEY[i];
        a-= NUMBER_SHIFR;
        for(int i = 0; i<text.length(); i++) text[i] = shifr(text[i], Kstr, a%(i+1), is_coder);
    }

    return text;
}

QChar shifr(QChar ch, QChar* KEY, int p_z, bool is_coder){
    ushort a = KEY[0].unicode(),
           b = KEY[1].unicode(),
           c = KEY[2].unicode(),
           d = KEY[3].unicode();

    int gamma =  p_z*(a + b*d  + d*a ) - a*b - c*d;
    int sm = (int) (p_z*(11.0/255.0) + 5);																			//Çàäàåì ñìåùåíèå è ñìåùàåì(ðàíäîìèçèðóåì) ãàììó
    gamma = (gamma>>sm) | (gamma<<sm);
    gamma = (char)(gamma ) + (char)(gamma>>24) - (char)(gamma>>16) + (char)(gamma>>8) ;						//Ïàêóåì ãàììó â char ïîïóòíî ðàíäîìèçèðóåì

    if(is_coder) ch = ch.unicode() + gamma;																					//Íàêëàäûâàåì èëè ñíèìàåì ãàììó
    else  	     ch = ch.unicode() - gamma;

    return ch;
}

QString key_generate(){
    QString KEY ="";
    for( int i=0; i<level_coder * NUMBER_SHIFR * 6; i++) KEY += (char)(rand()%256);
    return KEY;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(is_coder) w.coder_select();
    else w.decoder_select();
    if(is_file) w.file_select();
    else w.text_select();
    w.show();



    return a.exec();
}
