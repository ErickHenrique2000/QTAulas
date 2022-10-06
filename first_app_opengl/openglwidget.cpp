#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void OpenGLWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(1,1,1,1);
    QObject::connect(&timer, &QTimer::timeout,[&](){this->update();});
    timer.start(1);
}

void OpenGLWidget::resizeGL(int w, int h){

}

void OpenGLWidget::paintGL(){
    blinkFlag =! blinkFlag;

    red = (red + 0.001);
    if(red > 1){
        red -=1;
    }
    green += 0.002;
    if(green > 1){
        green -=1;
    }
    blue += 0.003;
    if(blue > 1){
        blue -=1;
    }
    /*
    if(blinkFlag){
        glClearColor(1, 1, 1, 1);
    }else{
        glClearColor(0, 0, 0, 1);
    }
    */
    glClearColor(red, green, blue, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWidget::toggleDarkMode(bool changeToDarkMode){
    makeCurrent();
    if(changeToDarkMode){
        glClearColor(0,0,0,1);
    }else{
        glClearColor(1,1,1,1);
    }
    update();
}
