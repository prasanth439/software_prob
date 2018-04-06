#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H
#include <vector>
#include <QGLWidget>
#include<QMouseEvent>
#include "ThreeD.h"

class OpenglWindow : public QGLWidget
{
    Q_OBJECT
public:
    ThreeD *oh;
public:
    explicit OpenglWindow(QWidget *parent=0);
    ~OpenglWindow();
     int list_number;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    //QSize minimumSizeHint() const;
    //QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    void draw();
    void draw_axes();
    void draw_top();
    void draw_side();
    void draw_front();
    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;
};

#endif // OPENGLWINDOW_H
