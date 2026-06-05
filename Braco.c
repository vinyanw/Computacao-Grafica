#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
int ombro = 0, cotovelo = 0;

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // etapa corpo|tronco
  glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // Cor preta para as linhas do tronco
    glScalef(2.0, 3.0, 1.0);  // Um retângulo vertical (Largura: 2, Altura: 3)
    glutWireCube(1.0);
  glPopMatrix();

  // etapa perna esqeerda
  glPushMatrix();
    glTranslatef(-0.6, -2.5, 0.0); 
    glColor3f(0.2, 0.2, 0.2);
    glScalef(0.6, 2.0, 1.0);  // Retângulo vertical para a perna
    glutWireCube(1.0);
  glPopMatrix();

  // etapa perna direita
  glPushMatrix();
    glTranslatef(0.6, -2.5, 0.0); 
    glColor3f(0.2, 0.2, 0.2);
    glScalef(0.6, 2.0, 1.0);  // Retângulo vertical para a perna
    glutWireCube(1.0);
  glPopMatrix();

  // braço esquerdo
  glPushMatrix();
    glTranslatef(-1.0, 1.2, 0.0);
    glRotatef((GLfloat)ombro, 0.0, 0.0, 1.0);
    glTranslatef(-1.0, 0.0, 0.0);

    glPushMatrix();
      glColor3f(0.5, 0.0, 0.0); // Vermelho escuro
      glScalef(2.0, 0.5, 1.0);
      glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)cotovelo, 0.0, 0.0, 1.0);
    glTranslatef(-1.0, 0.0, 0.0);

    glPushMatrix();
      glColor3f(0.0, 0.0, 0.5); // Azul escuro
      glScalef(2.0, 0.5, 1.0);
      glutWireCube(1.0);
    glPopMatrix();

  glPopMatrix(); // Fecha o braço esquerdo

  // braço direito
  glPushMatrix();
    glTranslatef(1.0, 1.2, 0.0);
    glRotatef((GLfloat)-ombro, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
      glColor3f(0.5, 0.0, 0.0); // Vermelho escuro
      glScalef(2.0, 0.5, 1.0);
      glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)-cotovelo, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
      glColor3f(0.0, 0.0, 0.5); // Azul escuro
      glScalef(2.0, 0.5, 1.0);
      glutWireCube(1.0);
    glPopMatrix();
  glPopMatrix(); // fecha o braço direito

  //cabeça
  glPushMatrix();
  glTranslatef(0.0, 2.0, 0.5);
  glScalef(1.0, 1.0, 1.0);  // Um retângulo vertical (Largura: 2, Altura: 3)
    glutWireCube(1.0);
  glPopMatrix();

  //olho esquerdo
  glPushMatrix();
  glTranslatef(-0.25, 2.25, 0);
  glScalef(0.2, 0.2, 1.0);  // Um retângulo vertical (Largura: 2, Altura: 3)
    glutWireCube(0.5);
  glPopMatrix();

 //olho direito
  glPushMatrix();
  glTranslatef(0.25, 2.25, 0);
  glScalef(0.2, 0.2, 1.0);  // Um retângulo vertical (Largura: 2, Altura: 3)
    glutWireCube(0.5);
  glPopMatrix();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
  gluLookAt(0, 0, 8, 0, 0, 0, 0, 1, 0); 
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'a':
      if (ombro>80)
      {
        break;
      } else {
        ombro = (ombro + 5) % 360;
        printf("Valor do Ombro: %d\n", ombro); 
        glutPostRedisplay();
        break;
      }
    case 'd':
      if (ombro < (-70)) {
        break;
      }
      else {
        ombro = (ombro - 5) % 360;
        printf("Valor do Ombro: %d\n", ombro); 
        glutPostRedisplay();
        break;
      }
    case 's':
      if (cotovelo > 135)
      {
        break;
      } else {
        cotovelo = (cotovelo + 5) % 360;
        printf("Valor do Cotovelo: %d\n", cotovelo); 
        glutPostRedisplay();
        break;
      }
      
    case 'w':
      if (cotovelo < (-130))
      {
        break;
      }
      cotovelo = (cotovelo - 5) % 360;
      printf("Valor do Cotovelo: %d\n", cotovelo); 
      glutPostRedisplay();
      break;
    case 27: // ESC
      exit(0);
      break;
    default:
      break;
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Boneco quadrado feio com cabeça");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutMainLoop();
  return 0;
}