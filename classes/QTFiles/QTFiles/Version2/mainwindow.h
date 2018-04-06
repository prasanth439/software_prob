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
    void handle_compute();
    void closeEvent(QCloseEvent *event);
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionTopView_triggered();
    void on_actionSideView_triggered();
    void on_actionFrontView_triggered();
    void on_actionPerspectiveView_triggered();

private:
    Ui::MainWindow *ui;
    QString file_name_Top=QString();
    QString file_name_Side=QString();
    QString file_name_Front=QString();
    QString file_name_Perspecitive=QString();

};

#endif // MAINWINDOW_H
