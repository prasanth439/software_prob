#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include<QMessageBox>
#include<QCloseEvent>
#include<QFileDialog>
#include "openglwindow.h"
#include<QFile>
#include "twodtothreed.h"
#include<fstream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->push_front,SIGNAL(clicked(bool)),this,SLOT(handle_clicks()));
    connect(ui->push_top,SIGNAL(clicked(bool)),this,SLOT(handle_clicks()));
    connect(ui->push_side,SIGNAL(clicked(bool)),this,SLOT(handle_clicks()));
    connect(ui->Compute,SIGNAL(clicked(bool)),this,SLOT(handle_compute()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle_clicks()
{
    QPushButton* button = (QPushButton*)sender();
    ui->label->setText(button->text());
//    if(button->text() == "Front_view"){

//    }
//    else if(button->text() == "Side_view"){

//    }
//    else if(button->text() == "Pers")
}
void MainWindow::handle_compute()
{
    if(file_name_Perspecitive!=QString()){
        std::string buf = (file_name_Perspecitive.toUtf8().constData());
        (ui->openglWindow->oh)->from_threed_file(buf);
        ui->openglWindow->oh->ready = true;
        qDebug()<<ui->openglWindow->oh->ready;
        qDebug()<<ui->openglWindow->oh->vertex_list_pers[4]->x<<" Hello world";
    }
    else if(file_name_Front!=QString()&&file_name_Side!=QString()&&file_name_Top!=QString()){
        std::string buf1 = (file_name_Front.toUtf8().constData());
        std::string buf2 = (file_name_Side.toUtf8().constData());
        std::string buf3 = file_name_Top.toUtf8().constData();
        twod_to_threed(ui->openglWindow->oh,buf1,buf3,buf2);
        ui->openglWindow->oh->ready = true;

    }
    else{
        //
    }
}

void MainWindow::on_actionOpen_triggered()
{

    int n;
    qDebug()<<"open is triggered";
    QString lab = ui->label->text();
    if(lab=="FrontView"){
        file_name_Front = QFileDialog::getOpenFileName(this,"Open ..","/home/prasanth/WorkSpace/QTProjects/","All Files (*.*);;Text Files (*.txt)");
    }
    else if(lab=="TopView"){
        file_name_Top = QFileDialog::getOpenFileName(this,"Open ..","/home/prasanth/WorkSpace/QTProjects/","All Files (*.*);;Text Files (*.txt)");
    }
    else if(lab=="SideView"){
        file_name_Side = QFileDialog::getOpenFileName(this,"Open ..","/home/prasanth/WorkSpace/QTProjects/","All Files (*.*);;Text Files (*.txt)");
    }
    else{
        file_name_Perspecitive = QFileDialog::getOpenFileName(this,"Open ..","/home/prasanth/WorkSpace/QTProjects/","All Files (*.*);;Text Files (*.txt)");
    }
    //QString file_nam = QFileDialog::getOpenFileName(this,"Open ..","/home/prasanth/WorkSpace/QTProjects/","All Files (*.*);;Text Files (*.txt)");
    //QFile file = Qfile
    //qDebug()<<file_nam<<" "<<lab;
    //qDebug()<<n;
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
    ui->openglWindow->list_number = 2;
}\
void MainWindow::on_actionTopView_triggered(){
    //on_actionOpen_triggered();
    ui->label->setText("TopView");
    ui->openglWindow->list_number = 1;
}
void MainWindow::on_actionFrontView_triggered(){
    //on_actionOpen_triggered();
    ui->label->setText("FrontView");
    ui->openglWindow->list_number = 3;
}
void MainWindow::on_actionPerspectiveView_triggered(){
    ui->label->setText("PerspectiveView");
    ui->openglWindow->list_number = 0;
}
