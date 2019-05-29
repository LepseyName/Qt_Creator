#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include<QDesktopServices>

#define NUMBER_SHIFR 4

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filewindow = new FileWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete filewindow;
}
void MainWindow::file_select(){
    this->on_radioButton_mode_in_file_clicked();
}
void MainWindow::text_select(){
    this->on_radioButton_mode_text_clicked();
}
void MainWindow::coder_select(){
    this->on_radioButton_coder_clicked();
}
void MainWindow::decoder_select(){
    this->on_radioButton_decoder_clicked();
}


void MainWindow::update()
{
    ui->textEdit_output_text->setText(coder( ui->textEdit_input_text->toPlainText(), ui->lineEdit_key->text()));
}

void MainWindow::on_textEdit_input_text_textChanged(){
   this->update();
}

void MainWindow::on_lineEdit_key_textChanged(const QString &arg1)
{
    this->update();
}


void MainWindow::on_radioButton_key_random_clicked()
{
    ui->lineEdit_key->setReadOnly(true);
    ui->lineEdit_key->setText(key_generate());
    this->update();
}

void MainWindow::on_radioButton_key_your_clicked()
{
    ui->lineEdit_key->setReadOnly(false);
    this->update();
}

void MainWindow::on_radioButton_coder_clicked()
{
    ui->radioButton_coder->setChecked(true);
    set_coder(true);
    this->update();
}

void MainWindow::on_radioButton_decoder_clicked()
{
    ui->radioButton_decoder->setChecked(true);
    set_coder(false);
    this->update();
}

void MainWindow::on_radioButton_mode_text_clicked()
{

}

void MainWindow::on_radioButton_mode_in_file_clicked()
{
    ui->radioButton_mode_text->setChecked(true);

    connect(filewindow, &FileWindow::TextWindow, this, &MainWindow::show);
    filewindow->setGeometry(this->geometry());
    filewindow->setWindowTitle((this->windowTitle()));
    filewindow->show();

    this->close();
}

void MainWindow::on_actionGitHab_triggered()
{
   QDesktopServices::openUrl(QUrl("https://doc.qt.io/archives/qt-4.8/qdesktopservices.html#openUrl"));
}

void MainWindow::on_action_5_triggered()
{
    QDesktopServices::openUrl(QUrl("https://vk.com/vadya_pugachov"));
}

void MainWindow::on_action4pda_triggered()
{
    QDesktopServices::openUrl(QUrl("http://4pda.ru/"));
}
