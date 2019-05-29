#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QFileDialog>
#include <QFile>
#include <QDesktopServices>
#define NUMBER_SHIFR 4

FileWindow::FileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileWindow)
{
    ui->setupUi(this);
}

FileWindow::~FileWindow()
{
    delete ui;
}

void FileWindow::update()
{
    ui->label_error_in_file->setText("");
}

void FileWindow::on_lineEdit_input_file_textChanged(const QString &arg1)
{
    this->update();
}

void FileWindow::on_lineEdit_output_file_textChanged(const QString &arg1)
{
    this->update();
}

void FileWindow::on_pushButton_select_file_clicked()
{
    ui->lineEdit_input_file->setText(QFileDialog::getOpenFileName(
                                this,
                                QString("Открыть файл"),
                                QString("/home"),
                                QString()));
    this->update();
}

void FileWindow::on_pushButton_select_output_file_clicked()
{
    ui->lineEdit_output_file->setText(QFileDialog::getSaveFileName(
                                this,
                                QString("Сохранить файл"),
                                QString("/home/xxx.sec"),
                                QString()));
    this->update();
}

void FileWindow::on_run_clicked()
{
    if( ui->lineEdit_input_file->text().length()==0){
        ui->label_error_in_file->setText("Нужен входной файл!");
        return;
    }
    if( !QFile::exists(ui->lineEdit_input_file->text())){
        ui->label_error_in_file->setText("Файл не существует или не может быть открыт!");
        return;
    }
    if( ui->lineEdit_output_file->text().length()==0){
        ui->label_error_in_file->setText("Нужен выходной файл!");
        return;
    }
    if( ui->lineEdit_key->text().length()== 0 || ui->lineEdit_key->text().length()%NUMBER_SHIFR!=0){
        ui->label_error_in_file->setText("Неправильный код!\nДолжен быть кратен "+QString::number(NUMBER_SHIFR));
        return;
    }
    QFile input_file(ui->lineEdit_input_file->text()),
          output_file(ui->lineEdit_output_file->text());
    if (!input_file.open(QIODevice::ReadOnly)) {
        ui->label_error_in_file->setText("Входной файл не открыт!");
        return;
    }
    if (!output_file.open(QIODevice::WriteOnly)){
        ui->label_error_in_file->setText("Выходной файл не открыт!");
        return;
    }

    coder(input_file, output_file, ui->lineEdit_key->text());

    input_file.close();
    output_file.close();
    ui->label_error_in_file->setText("Конец");
}

void FileWindow::on_radioButton_key_random_clicked()
{
    ui->lineEdit_key->setReadOnly(true);
    ui->lineEdit_key->setText(key_generate());
    this->update();
}

void FileWindow::on_radioButton_key_your_clicked()
{
    ui->lineEdit_key->setReadOnly(false);
    this->update();
}

void FileWindow::on_radioButton_mode_text_clicked()
{
    ui->radioButton_mode_in_file->setChecked(true);
    this->close();
    emit TextWindow();
}

void FileWindow::on_radioButton_coder_clicked()
{
    ui->radioButton_coder->setChecked(true);
    set_coder(true);
    this->update();
}

void FileWindow::on_radioButton_decoder_clicked()
{
    ui->radioButton_decoder->setChecked(true);
    set_coder(false);
    this->update();
}

void FileWindow::on_actionGitHab_triggered()
{
   QDesktopServices::openUrl(QUrl("https://doc.qt.io/archives/qt-4.8/qdesktopservices.html#openUrl"));
}

void FileWindow::on_action_5_triggered()
{
    QDesktopServices::openUrl(QUrl("https://vk.com/vadya_pugachov"));
}

void FileWindow::on_action4pda_triggered()
{
    QDesktopServices::openUrl(QUrl("http://4pda.ru/"));
}
