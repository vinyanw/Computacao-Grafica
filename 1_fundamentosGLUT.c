#include <GL/glut.h>

void desenhaCena(void) {
    // 1. Limpa o ecrã com a cor de fundo definida
    glClear(GL_COLOR_BUFFER_BIT);

    // 2. Desenha o Retângulo Azul
    glColor3f(0.0f, 0.0f, 1.0f); // Estado: Azul ativo
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.2f, 0.2f);
        glVertex2f(0.8f, 0.2f);
        glVertex2f(0.8f, 0.6f);
        glVertex2f(0.2f, 0.6f);
    glEnd();

    glPointSize(30.0f);
    // 3. Desenha o Ponto (que continua azul)
    glBegin(GL_POINTS);
        glVertex2f(0.5f, 0.5f); // Ponto no centro
    glEnd();

    // Troca os buffers (se estiver a usar GLUT_DOUBLE)
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Janela criada com GLUT");
    glutDisplayFunc(desenhaCena);
    //glutReshapeFunc(alteraTamanho);
    //glutKeyboardFunc(gereTeclado);
    glutMainLoop();

}
