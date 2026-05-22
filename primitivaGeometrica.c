#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // fundo branco
    gluOrtho2D(0.0, 100.0, 0.0, 100.0); // sistema de coordenadas
}

void desenharCasa() {
    // ===== 1. RETÂNGULO PRINCIPAL (corpo da casa) =====
    glColor3f(0.8, 0.7, 0.5); // bege/marrom claro
    glBegin(GL_QUADS);
        glVertex2f(30, 30);
        glVertex2f(70, 30);
        glVertex2f(70, 60);
        glVertex2f(30, 60);
    glEnd();
    
    // ===== 2. RETÂNGULO TORTO (TELHADO) =====
    glColor3f(0.6, 0.3, 0.1); // marrom
    glBegin(GL_QUADS);
        glVertex2f(25, 60);
        glVertex2f(75, 60);
        glVertex2f(70, 75);
        glVertex2f(30, 75);
    glEnd();
    
    // ===== 3. TRIÂNGULO NO TETO (topo do telhado) =====
    glColor3f(0.8, 0.2, 0.1); // vermelho tijolo
    glBegin(GL_TRIANGLES);
        glVertex2f(30, 75);
        glVertex2f(70, 75);
        glVertex2f(50, 90);
    glEnd();
    
    // ===== 4. JANELA ESQUERDA (2 quadrados + linhas) =====
    // Quadrado superior esquerdo da janela
    glColor3f(0.0, 0.6, 0.9); // azul claro (vidro)
    glBegin(GL_QUADS);
        glVertex2f(38, 45);
        glVertex2f(46, 45);
        glVertex2f(46, 53);
        glVertex2f(38, 53);
    glEnd();
    
    // Quadrado inferior esquerdo da janela
    glBegin(GL_QUADS);
        glVertex2f(38, 37);
        glVertex2f(46, 37);
        glVertex2f(46, 45);
        glVertex2f(38, 45);
    glEnd();
    
    // Linha horizontal da janela esquerda
    glColor3f(0.0, 0.0, 0.0); // preta
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2f(38, 45);
        glVertex2f(46, 45);
    glEnd();
    
    // Linha vertical da janela esquerda
    glBegin(GL_LINES);
        glVertex2f(42, 37);
        glVertex2f(42, 53);
    glEnd();
    
    // ===== 5. JANELA DIREITA (2 quadrados + linhas) =====
    // Quadrado superior direito
    glColor3f(0.0, 0.6, 0.9);
    glBegin(GL_QUADS);
        glVertex2f(54, 45);
        glVertex2f(62, 45);
        glVertex2f(62, 53);
        glVertex2f(54, 53);
    glEnd();
    
    // Quadrado inferior direito
    glBegin(GL_QUADS);
        glVertex2f(54, 37);
        glVertex2f(62, 37);
        glVertex2f(62, 45);
        glVertex2f(54, 45);
    glEnd();
    
    // Linha horizontal
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(54, 45);
        glVertex2f(62, 45);
    glEnd();
    
    // Linha vertical
    glBegin(GL_LINES);
        glVertex2f(58, 37);
        glVertex2f(58, 53);
    glEnd();
    
    // ===== 6. PORTA (um dos 3 quadrados) =====
    glColor3f(0.5, 0.3, 0.1); // madeira
    glBegin(GL_QUADS);
        glVertex2f(45, 30);
        glVertex2f(55, 30);
        glVertex2f(55, 42);
        glVertex2f(45, 42);
    glEnd();
    
    // Maçaneta
    glColor3f(1.0, 0.8, 0.0); // dourado
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glVertex2f(53, 36);
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
    glutCreateWindow("Casa com Primitivas OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}