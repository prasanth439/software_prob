#include "openglwindow.h"
#include <QtDebug>
#include<vector>
#include "vertex.h"
#include "edge.h"
#include "ThreeD.h"
OpenglWindow::OpenglWindow(QWidget *parent):
        QGLWidget(parent)
{

    Vertex *a1= new Vertex(0.0,0.0,0.0,1);
    Vertex *a2= new Vertex(0.0,0.0,1.0,2);
    Vertex *a3= new Vertex(0.0,1.0,0.0,3);
    Vertex *a4= new Vertex(1.0,0.0,0.0,4);
    Vertex *a5= new Vertex(1.0,1.0,0.0,5);
    Vertex *a6= new Vertex(0.0,1.0,1.0,6);
    Vertex *a7= new Vertex(1.0,0.0,1.0,7);
    Vertex *a8= new Vertex(1.0,1.0,1.0,8);
    Edge *b1= new Edge(a1,a2);
    Edge *b2= new Edge(a1,a3);
    Edge *b3 = new Edge(a1,a4);
    Edge *b5 = new Edge(a2,a7);
    Edge *b6 = new Edge(a2,a6);
    Edge *b7 = new Edge(a3,a6);
    Edge *b8 = new Edge(a3,a5);
    Edge *b9 = new Edge(a4,a5);
    Edge *b4 = new Edge(a4,a7);
    Edge *b10 = new Edge(a8,a6);
    Edge *b11 = new Edge(a5,a8);
    Edge *b12 = new Edge(a8,a7);
    std::vector<Edge *> edgeSur;
    edgeSur.push_back(b1);
    edgeSur.push_back(b2);
    edgeSur.push_back(b3);
    edgeSur.push_back(b4);
    edgeSur.push_back(b5);
    edgeSur.push_back(b6);
    edgeSur.push_back(b7);
    edgeSur.push_back(b8);
    edgeSur.push_back(b9);
    edgeSur.push_back(b10);
    edgeSur.push_back(b11);
    edgeSur.push_back(b12);
    oh = new ThreeD(edgeSur);
}

OpenglWindow::~OpenglWindow()
{

}

void OpenglWindow::initializeGL()
{

     glClearColor(0,1,0,0);

   // qDebug()<<(oh->edge_list[1])->p->x;
     int size = oh->edge_list.size();
     for(int i=0;i<size;i++){
         glBegin(GL_LINES);
             glVertex3d((oh->edge_list[i]->p)->x,(oh->edge_list[i]->p)->y,(oh->edge_list[i]->p)->z);
             glVertex3d((oh->edge_list[i]->q)->x,(oh->edge_list[i]->q)->y,(oh->edge_list[i]->q)->z);
         glEnd();
     }
}

void OpenglWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushAttrib(GL_ENABLE_BIT);
    // glPushAttrib is done to return everything to normal after drawing
    glColor3f(0.6,0.1,1);
    glLineStipple(1, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    //qDebug()<<(oh.oh.edge_list[1]).p->x;
    draw();
    glPopAttrib();
}

void OpenglWindow::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    //qDebug()<<width<<" "<<height;

}
void OpenglWindow::draw(){
    int size = oh->edge_list.size();
    for(int i=0;i<size;i++){
        glBegin(GL_LINES);
            glVertex3d((oh->edge_list[i]->p)->x,(oh->edge_list[i]->p)->y,(oh->edge_list[i]->p)->z);
            glVertex3d((oh->edge_list[i]->q)->x,(oh->edge_list[i]->q)->y,(oh->edge_list[i]->q)->z);
        glEnd();
    }
    qDebug()<<size;
}
