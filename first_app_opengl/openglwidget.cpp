#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void OpenGLWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(1,1,1,1);
}

void OpenGLWidget::resizeGL(int w, int h){

}

void OpenGLWidget::paintGL(){
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
