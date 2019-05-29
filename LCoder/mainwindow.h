#include <QFile>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void coder_select();
    void decoder_select();
    void file_select();
    void text_select();



private slots:
    void update();

    void on_lineEdit_key_textChanged(const QString &arg1);

    void on_textEdit_input_text_textChanged();

    void on_radioButton_key_random_clicked();

    void on_radioButton_key_your_clicked();

    void on_radioButton_coder_clicked();

    void on_radioButton_decoder_clicked();

    void on_radioButton_mode_text_clicked();

    void on_radioButton_mode_in_file_clicked();

    void on_actionGitHab_triggered();

    void on_action_5_triggered();

    void on_action4pda_triggered();

private:
    Ui::MainWindow *ui;
    FileWindow *filewindow;
};


void set_coder(bool);
QString key_generate();
QString coder(QString, QString);
QChar shifr(QChar, QChar*, int, bool is_coder= true);

#endif // MAINWINDOW_H
