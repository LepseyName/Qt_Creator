#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class FileWindow;
}

class FileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileWindow(QWidget *parent = nullptr);
    ~FileWindow();
    void update();

signals:
    void TextWindow();

private slots:


    void on_lineEdit_input_file_textChanged(const QString &arg1);

    void on_lineEdit_output_file_textChanged(const QString &arg1);

    void on_pushButton_select_file_clicked();

    void on_pushButton_select_output_file_clicked();

    void on_run_clicked();

    void on_radioButton_key_random_clicked();

    void on_radioButton_key_your_clicked();

    void on_radioButton_mode_text_clicked();

    void on_radioButton_coder_clicked();

    void on_radioButton_decoder_clicked();

    void on_actionGitHab_triggered();

    void on_action_5_triggered();

    void on_action4pda_triggered();

private:
    Ui::FileWindow *ui;
};

void set_coder(bool);
void coder(QFile&, QFile&, QString);
char* shifr(char*, QChar*, int, bool is_coder= true);
QString key_generate();

#endif // MAINWINDOW2_H
