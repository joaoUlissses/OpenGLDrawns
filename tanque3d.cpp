#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

    GLUquadric* quad;
    float angleX = 0.0f;
    float angleY = 0.0f;

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f);

    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    
        //corpo principal
    glBegin(GL_QUADS);//l1
    glColor3f(0.0, 0.0, 1.0); // Vermelho
        glVertex3f(-1.0, -1.0, 1.4);//a
        glVertex3f(1.0, -1.0, 1.4);//b
        glVertex3f(1.0, 0.5, 1.4);//c
        glVertex3f(-1.0, 0.5, 1.4);//d

    glBegin(GL_QUADS);//l6
        glVertex3d(-1.0,-1.0,-1.4);//h
        glVertex3f(1.0, -1.0, -1.4);//e
        glVertex3f(1.0, 0.5, -1.4);//f
        glVertex3d(-1.0,0.5,-1.4);//g

    glBegin(GL_QUADS);//l3
        glVertex3f(1.0, -1.0, 1.4);//b
        glVertex3f(1.0, 0.5, 1.4);//c
        glVertex3f(1.0, 0.5, -1.4);//f
        glVertex3f(1.0, -1.0, -1.4);//e

    glBegin(GL_QUADS);//l4
        glVertex3f(-1.0, -1.0, 1.4);//a
        glVertex3d(-1.0,-1.0,-1.4);//h
        glVertex3d(-1.0,0.5,-1.4);//g
        glVertex3f(-1.0, 0.5, 1.4);//d

    glBegin(GL_QUADS);//l2
        glVertex3f(1.0, 0.5, 1.4);//c
        glVertex3f(1.0, 0.5, -1.4);//f
        glVertex3d(-1.0,0.5,-1.4);//g
        glVertex3f(-1.0,0.5, 1.4);//d

    glBegin(GL_QUADS);//l5 
        glVertex3f(-1.0, -1.0, 1.4);//a
        glVertex3f(1.0, -1.0, 1.4);//b
        glVertex3f(1.0, -1.0, -1.4);//e
        glVertex3d(-1.0,-1.0,-1.4);//h
        

    //roda esquerda 
    glBegin(GL_QUADS);//l1
    glColor3f(1.0f,1.0f,0.0f); //amarelo
        glVertex3f(0.7,-0.5,1.6);//a
        glVertex3f(1.7,-0.5,1.6);//b
        glVertex3f(1.7,-1.2,1.6);//c
        glVertex3f(0.7,-1.2,1.6);//d
    glBegin(GL_QUADS);//l6
        glVertex3f(0.7,-0.5,-1.6);//h
        glVertex3f(1.7,-0.5,-1.6);//e
        glVertex3f(1.7,-1.2,-1.6);//f
        glVertex3f(0.7,-1.2,-1.6);//g
    glBegin(GL_QUADS);//l2
        glVertex3f(1.7,-1.2,1.6);//c
        glVertex3f(1.7,-1.2,-1.6);//f
        glVertex3f(0.7,-1.2,-1.6);//g
        glVertex3f(0.7,-1.2,1.6);//d
    glBegin(GL_QUADS);//l5
        glVertex3f(0.7,-0.5,1.6);//a
        glVertex3f(1.7,-0.5,1.6);//b
        glVertex3f(1.7,-0.5,-1.6);//e
        glVertex3f(0.7,-0.5,-1.6);//h
    glBegin(GL_QUADS);//l3
        glVertex3f(1.7,-0.5,1.6);//b
        glVertex3f(1.7,-1.2,1.6);//c
        glVertex3f(1.7,-1.2,-1.6);//f
        glVertex3f(1.7,-0.5,-1.6);//e

    glBegin(GL_QUADS);//l4
        glVertex3f(0.7,-0.5,1.6);//a
        glVertex3f(0.7,-0.5,-1.6);//h
        glVertex3f(0.7,-1.2,-1.6);//g
        glVertex3f(0.7,-1.2,1.6);//d
    //roda direita
    glBegin(GL_QUADS);//l1
    glColor3f(1.0f,1.0f,0.0f); //amarelo
        glVertex3f(-0.7,-0.5,1.6);//a
        glVertex3f(-1.7,-0.5,1.6);//b
        glVertex3f(-1.7,-1.2,1.6);//c
        glVertex3f(-0.7,-1.2,1.6);//d
    glBegin(GL_QUADS);//l6
        glVertex3f(-0.7,-0.5,-1.6);//h
        glVertex3f(-1.7,-0.5,-1.6);//e
        glVertex3f(-1.7,-1.2,-1.6);//f
        glVertex3f(-0.7,-1.2,-1.6);//g
    glBegin(GL_QUADS);//l2
        glVertex3f(-1.7,-1.2,1.6);//c
        glVertex3f(-1.7,-1.2,-1.6);//f
        glVertex3f(-0.7,-1.2,-1.6);//g
        glVertex3f(-0.7,-1.2,1.6);//d
    glBegin(GL_QUADS);//l5
        glVertex3f(-0.7,-0.5,1.6);//a
        glVertex3f(-1.7,-0.5,1.6);//b
        glVertex3f(-1.7,-0.5,-1.6);//e
        glVertex3f(-0.7,-0.5,-1.6);//h
    glBegin(GL_QUADS);//l3 
        glVertex3f(-1.7,-0.5,1.6);//b
        glVertex3f(-1.7,-1.2,1.6);//c
        glVertex3f(-1.7,-1.2,-1.6);//f
        glVertex3f(-1.7,-0.5,-1.6);//e

    glBegin(GL_QUADS);//l4
        glVertex3f(-0.7,-0.5,1.6);//a
        glVertex3f(-0.7,-0.5,-1.6);//h
        glVertex3f(-0.7,-1.2,-1.6);//g
        glVertex3f(-0.7,-1.2,1.6);//d

    //torre
    glBegin(GL_QUADS);//l1
    glColor3f(0.0f,1.0f,0.0f);
        glVertex3d(-0.4,0.5,-0.7);//a
        glVertex3f(0.4, 0.5,-0.7);//b
        glVertex3d(0.4,1.3,-0.7);//c
        glVertex3f(-0.4, 1.3,-0.7);//d
    glBegin(GL_QUADS);//l6
        glVertex3d(-0.4,0.5,0.4);//h
        glVertex3f(0.4, 0.5,0.4);//e
        glVertex3d(0.4,1.3,0.4);//f
        glVertex3f(-0.4,1.3,0.4);//g
    glBegin(GL_QUADS);//l3
        glVertex3f(0.4, 0.5,-0.7);//b
        glVertex3d(0.4,1.3,-0.7);//c
        glVertex3d(0.4,1.3,0.4);//f
        glVertex3f(0.4, 0.5,0.4);//e
    glBegin(GL_QUADS);//l4
        glVertex3d(-0.4,0.5,-0.7);//a
        glVertex3d(-0.4,0.5,0.4);//h
        glVertex3f(-0.4,1.3,0.4);//g
        glVertex3f(-0.4, 1.3,-0.7);//d
    glBegin(GL_QUADS);//l2
        glVertex3d(0.4,1.3,-0.7);//c
        glVertex3d(0.4,1.3,0.4);//f
        glVertex3f(-0.4,1.3,0.4);//g
        glVertex3f(-0.4, 1.3,-0.7);//d

    //canhao
    glBegin(GL_QUADS);//l1
    glColor3f(0.85f,0.0f,0.9f);//l1 excluir depois por ser inutil
        glVertex3d(-0.2,0.7,0.4);//a
        glVertex3f(0.2, 0.7,0.4);//b
        glVertex3d(0.2,1.0,0.4);//c
        glVertex3f(-0.2,1.0,0.4);//d
    glBegin(GL_QUADS);// l6
        glVertex3d(-0.2,0.7,2.4);//h
        glVertex3f(0.2, 0.7,2.4);//e
        glVertex3d(0.2,1.0,2.4);//f
        glVertex3f(-0.2,1.0,2.4);//g
    glBegin(GL_QUADS);// 2
        glVertex3d(0.2,1.0,0.4);//c
        glVertex3d(0.2,1.0,2.4);//f
        glVertex3f(-0.2,1.0,2.4);//g
        glVertex3f(-0.2,1.0,0.4);//d
    glBegin(GL_QUADS);// 5
        glVertex3d(-0.2,0.7,0.4);//a
        glVertex3f(0.2, 0.7,0.4);//b
        glVertex3f(0.2, 0.7,2.4);//e
        glVertex3d(-0.2,0.7,2.4);//h
    glBegin(GL_QUADS);// 3
        glVertex3f(0.2, 0.7,0.4);//b
        glVertex3d(0.2,1.0,0.4);//c
        glVertex3d(0.2,1.0,2.4);//f
        glVertex3f(0.2, 0.7,2.4);//e
    glBegin(GL_QUADS);// 4
        glVertex3d(-0.2,0.7,0.4);//a
        glVertex3d(-0.2,0.7,2.4);//h
        glVertex3f(-0.2,1.0,2.4);//g
        glVertex3f(-0.2,1.0,0.4);//d
        
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