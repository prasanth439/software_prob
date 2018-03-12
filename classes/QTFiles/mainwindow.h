#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handle_clicks();
    void closeEvent(QCloseEvent *event);
    void on_actionOpen_triggered();
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QString file_name_Top;
    QString file_name_Side;
    QString file_name_Front;
    QString file_name_Perspecitive;

};

#endif // MAINWINDOW_H
