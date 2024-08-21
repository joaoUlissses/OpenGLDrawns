#include <GL\freeglut.h>
void inicializar(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}
void exibir(){
    glClear(GL_COLOR_BUFFER_BIT);

//corpo do tanque
    glColor3f(0.0f, 0.0f, 1.0f); //vermelho
    glBegin(GL_QUADS);

        glVertex2d(0.3f,0.4f);
        glVertex2d(-0.3f,0.4f);
        glVertex2d(-0.3f,-0.4f);
        glVertex2d(0.3f,-0.4f);
    glEnd();
//caixa do meio 
glColor3f(0.00f, 1.00f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2d(-0.2f,0.-0.2f);
        glVertex2d(0.2f,-0.2f);
        glVertex2d(0.2f,0.2f);
        glVertex2d(-0.2f,0.2f);
    glEnd();
//canhao do tanque
    glColor3f(0.70f, 0.18f, 0.68f); 
    glBegin(GL_QUADS);
        glVertex2d(0.05f,0.8f);
        glVertex2d(0.05f,0.15f);
        glVertex2d(-0.05f,0.15f);
        glVertex2d(-0.05f,0.8f);
    glEnd();
//roda esquerda
    glColor3f(0.9f, 1.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2d(-0.3f,0.5f);
        glVertex2d(-0.3f,-0.5f);
        glVertex2d(-0.5f,-0.5f);
        glVertex2d(-0.5f,0.5f);
    glEnd();
//roda direita
    glBegin(GL_QUADS);
        glVertex2d(0.3f,0.5f);
        glVertex2d(0.3f,-0.5f);
        glVertex2d(0.5f,-0.5f);
        glVertex2d(0.5f,0.5f);
    glEnd();


    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("primitivas em 2d no opengl");
    inicializar();
    glutDisplayFunc(exibir);
    glutMainLoop();
    return 0; 
}