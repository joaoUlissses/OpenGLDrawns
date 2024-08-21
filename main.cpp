#include <GL/freeglut.h>
#include <math.h>
void inicializar(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}
void desenharCirculo(float centroX, float centroY,float raio, int numSegmentos){
    glBegin(GL_LINE_LOOP);
    for(int i =0; i<numSegmentos;i++){
        float angulo = 2.0f *3.1415926f*float(i)/float(numSegmentos);
        float x = raio * cosf(angulo);
        float y =  raio* sinf(angulo);
        glVertex2f(x+centroX,y+centroY);
    }
    glEnd();
}
void exibir(){
    glClear(GL_COLOR_BUFFER_BIT);

    //substitua esse bloco
                                                /* dois pontos 
                                                glBegin(GL_POINTS);
                                                glVertex2f(0.0f,0.0f);
                                                glVertex2d(0.5f,0.5f);
                                                glEnd();

                                                LINHA
                                                glBegin(GL_LINES);
                                                    glVertex2f(0.0f,0.0f);
                                                    glVertex2d(0.5f,0.5f);
                                                glEnd();
                                                CUBO    
                                                glBegin(GL_LINE_LOOP);
                                                    glVertex2f(0.7f,0.7f);
                                                    glVertex2d(-0.7f,0.7f);
                                                    glVertex2d(-0.7f,-0.7f);
                                                    glVertex2d(0.7f,-0.7f);
                                                glEnd();
                                                CUBO FECHADO
                                                glBegin(GL_QUADS);
                                                    glVertex2f(0.5f,0.5f);
                                                    glVertex2d(-0.5f,0.5f);
                                                    glVertex2d(-0.5f,-0.5f);
                                                    glVertex2d(0.5f,-0.5f);
                                                glEnd();
                                               
                                                glBegin(GL_TRIANGLE_FAN);
                                                    glVertex2d(0.0f,0.5f);
                                                    glVertex2d(-0.8f,-0.5f);
                                                    glVertex2d(0.8f,-0.5f);
                                                glEnd(); 
                                                 */   
                                                //desenharCirculo(0.0f,0.0f,0.8f,16);
                                                
                                                                                      
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