#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include<QMessageBox>
#include<QCloseEvent>
#include<QFileDialog>
#include<QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->push_front,SIGNAL(clicked(bool)),this,SLOT(handle_clicks()));
    connect(ui->push_top,SIGNAL(clicked(bool)),this,SLOT(handle_clicks()));
    connect(ui->push_side,SIGNAL(clicked(bool)),this,SLOT(handle_clicks()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle_clicks()
{
    QPushButton* button = (QPushButton*)sender();
    ui->label->setText(button->text());
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug()<<"open is triggered";
    QString lab = ui->label->text();
    if(lab=="FrontView"){
        file_name_Front = QFileDialog::getOpenFileName(this,"Open ..","/home/","All Files (*.*);;Text Files (*.txt)");
    }
    else if(lab=="TopView"){
        file_name_Top = QFileDialog::getOpenFileName(this,"Open ..","/home/","All Files (*.*);;Text Files (*.txt)");
    }
    else if(lab=="SideView"){
        file_name_Side = QFileDialog::getOpenFileName(this,"Open ..","/home/","All Files (*.*);;Text Files (*.txt)");
    }
    else{
        file_name_Perspecitive = QFileDialog::getOpenFileName(this,"Open ..","/home/","All Files (*.*);;Text Files (*.txt)");
    }
    //QString file_nam = QFileDialog::getOpenFileName(this,"Open ..","/home/","All Files (*.*);;Text Files (*.txt)");
    //QFile file = Qfile
    //qDebug()<<file_nam<<" "<<lab;
}
void MainWindow::on_actionExit_triggered(){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Exit Window","Are you sure?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
         QApplication::quit();
    }
   else{
        //---Nothing  --//
    }
}
void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Exit Window","Are you sure?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
         event->accept();
    }
   else{
         event->ignore();
    }
}
void MainWindow::on_actionSideView_triggered(){
    //on_actionOpen_triggered();
    ui->label->setText("SideView");
}\
void MainWindow::on_actionTopView_triggered(){
    //on_actionOpen_triggered();
    ui->label->setText("TopView");
}
void MainWindow::on_actionFrontView_triggered(){
    //on_actionOpen_triggered();
    ui->label->setText("FrontView");
}
void MainWindow::on_actionPerspectiveView_triggered(){
    ui->label->setText("PerspectiveView");
}
