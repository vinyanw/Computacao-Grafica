#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // fundo branco
    gluOrtho2D(0.0, 100.0, 0.0, 100.0); // sistema de coordenadas
}

void desenharCasa() {
    // parede da fachada vermelha
    glColor3f(0.7, 0.2, 0.3); // vermelho
    glBegin(GL_QUADS);
        glVertex2f(10, 20);
        glVertex2f(40, 20);
        glVertex2f(40, 60);
        glVertex2f(10, 60);
    glEnd();

    // triângulo verde acima da fachada da casa
    glColor3f(0.0, 0.9, 0.0); // verde
    glBegin(GL_TRIANGLES);
        glVertex2f(10, 60);
        glVertex2f(25, 90);
        glVertex2f(40, 60);
    glEnd();

    // parede azul lateral da casa
    glColor3f(0.1, 0.1, 0.9); // azul escuro
    glBegin(GL_QUADS);
        glVertex2f(40, 20);
        glVertex2f(90, 20);
        glVertex2f(90, 60);
        glVertex2f(40, 60);
    glEnd();

    // teto lateral da caca
    glColor3f(0.2, 0.5, 0.8); // ciano
    glBegin(GL_QUADS);
        glVertex2f(40, 60);
        glVertex2f(90, 60);
        glVertex2f(80, 90);
        glVertex2f(25, 90);
    glEnd();

    // porta na frente da fachada vermelha
    glColor3f(0.8, 0.2, 1.0); // roxo
    glBegin(GL_QUADS);
        glVertex2f(18, 20);
        glVertex2f(30, 20);
        glVertex2f(30, 45);
        glVertex2f(18, 45);
    glEnd();

    // maçaneta na porta roxa
    glColor3f(0.3, 0.7, 1.0);
    glPointSize(6);
    glBegin(GL_POINTS);
        glVertex2f(22, 32);
    glEnd();

    // janela 1 (à ESQUERDA)
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_QUADS);
        glVertex2f(45, 35);
        glVertex2f(65, 35);
        glVertex2f(65, 50);
        glVertex2f(45, 50);
    glEnd();

    // duas linhas verticais e horizontais na janela 1
    glColor3f(0.0, 1.0, 0.7);
    glBegin(GL_LINES);
        glVertex2f(55, 35);
        glVertex2f(55, 50);

        glVertex2f(45, 42.5);
        glVertex2f(65, 42.5);
    glEnd();

    // janela 2 (à DIREITA)
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_QUADS);
        glVertex2f(70, 35);
        glVertex2f(90, 35);
        glVertex2f(90, 50);
        glVertex2f(70, 50);
    glEnd();

    // duas linhas verticais e horizontais na janela 2
    glColor3f(0.0, 1.0, 0.7);
    glBegin(GL_LINES);
        glVertex2f(80, 35);
        glVertex2f(80, 50);

        glVertex2f(70, 42.5);
        glVertex2f(90, 42.5);
    glEnd();

    // calçada azul abaixo da porta roxa
    glColor3f(0.23, 0.48, 0.2);
    glBegin(GL_QUADS);
        glVertex2d(0, 0);
        glVertex2d(20, 0);
        glVertex2f(30, 20);
        glVertex2f(18, 20);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    desenharCasa();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Primitivas OpenGL");
    init();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;
}