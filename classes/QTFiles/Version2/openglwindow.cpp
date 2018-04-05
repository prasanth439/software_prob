#include "openglwindow.h"
#include <QtDebug>
#include<vector>
#include "vertex.h"
#include "edge.h"
#include "ThreeD.h"
OpenglWindow::OpenglWindow(QWidget *parent):
        QGLWidget(parent)
{
    xRot = 0 ;
    yRot = 0 ;
    zRot = 0 ;

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

     qglClearColor(Qt::black);

     glEnable(GL_DEPTH_TEST);
     glEnable(GL_CULL_FACE);
     glShadeModel(GL_SMOOTH);
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
     static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
     glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void OpenglWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();
    glPushAttrib(GL_ENABLE_BIT);
}

void OpenglWindow::resizeGL(int width, int height)
{
   // glViewport(0,0,width,height);
    //qDebug()<<width<<" "<<height;




    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);

}
void OpenglWindow::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void OpenglWindow::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
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

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void OpenglWindow::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void OpenglWindow::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void OpenglWindow::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}
