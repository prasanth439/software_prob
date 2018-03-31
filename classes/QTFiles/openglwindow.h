#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H
#include <vector>
#include <QGLWidget>
#include "ThreeD.h"

class OpenglWindow : public QGLWidget
{
    Q_OBJECT
public:
    ThreeD *oh;
public:
    explicit OpenglWindow(QWidget *parent=0);
    ~OpenglWindow();
    void initializeGL();
    void paintGL();
    void resizeGL(int width,int height);
    void draw();
};

#endif // OPENGLWINDOW_H
