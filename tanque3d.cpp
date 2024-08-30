#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "stb_image.h"
#include <string>

    GLUquadric* quad;
    float angleX = 0.0f;
    float angleY = 0.0f;

// void carregarTextura(std::string filePath){
//     unsigned char* imgData;

//     imgData=stbi_load(filePath.c_str(),&largura, &aluta, &canais,4);
// }
void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void quadrado(float Ybaixo, float Ycima,float Xesquerda,float Xdireita,float Zfrente,float Zatras){
    //cubo
    glBegin(GL_QUADS);//l1
        glVertex3f(Xesquerda,Ybaixo,Zfrente);//a
        glVertex3f(Xdireita,Ybaixo,Zfrente);//b
        glVertex3f(Xdireita,Ycima,Zfrente);//c
        glVertex3f(Xesquerda,Ycima,Zfrente);//d
    glBegin(GL_QUADS);//l6
        glVertex3f(Xesquerda,Ybaixo,Zatras);//h
        glVertex3f(Xdireita,Ybaixo,Zatras);//e
        glVertex3f(Xdireita,Ycima,Zatras);//f
        glVertex3f(Xesquerda,Ycima,Zatras);//g
    glBegin(GL_QUADS);//l2
        glVertex3f(Xdireita,Ycima,Zfrente);//c
        glVertex3f(Xdireita,Ycima,Zatras);//f
        glVertex3f(Xesquerda,Ycima,Zatras);//g
        glVertex3f(Xesquerda,Ycima,Zfrente);//d
    glBegin(GL_QUADS);//l5
        glVertex3f(Xesquerda,Ybaixo,Zfrente);//a
        glVertex3f(Xdireita,Ybaixo,Zfrente);//b
        glVertex3f(Xdireita,Ybaixo,Zatras);//e
        glVertex3f(Xesquerda,Ybaixo,Zatras);//h
    glBegin(GL_QUADS);//l3
        glVertex3f(Xdireita,Ybaixo,Zfrente);//b
        glVertex3f(Xdireita,Ycima,Zfrente);//c
        glVertex3f(Xdireita,Ycima,Zatras);//f
        glVertex3f(Xdireita,Ybaixo,Zatras);//e
    glBegin(GL_QUADS);//l4
        glVertex3f(Xesquerda,Ybaixo,Zfrente);//a
        glVertex3f(Xesquerda,Ybaixo,Zatras);//h
        glVertex3f(Xesquerda,Ycima,Zatras);//g
        glVertex3f(Xesquerda,Ycima,Zfrente);//d
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f);

    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    
    //corpo principal
    glColor3f(0.0,0.0,1.0);
    quadrado(-1.0,0.5,-1.0,1.0,1.4,-1.4);
    //torre
    glColor3f(0.0,1.0,0.0);
    quadrado(0.5,1.3,-0.4,0.4,-0.7,0.4);
    //canhao
    glColor3f(0.85,0.0,0.9);
    quadrado(0.7,1.0,-0.2,0.2,0.4,2.4);
    //roda esquerda 
    glColor3f(1.0,1.0,0.0);
    quadrado(-1.2,-0.5,1.7,0.7,1.6,-1.6);
    //roda direita
    quadrado(-1.2,-0.5,-1.7,-0.7,1.6,-1.6);
        glEnd();

    glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    angleX += 0.2f;
    angleY += 0.3f;

    if (angleX > 360.0f) angleX -= 360.0f;
    if (angleY > 360.0f) angleY -= 360.0f;

    glutPostRedisplay(); // Marca a janela como "precisando ser redesenhada"
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("tanque 3d ");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle); // Chama a função idle continuamente para animar o cubo

    glutMainLoop();
    return 0;
}