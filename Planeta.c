#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

static int ano = 0, dia = 0;

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // sol (ou planeta amarelo, não sei)
  glPushMatrix();
    glColor3f(0.5, 0.5, 0.0); // Amarelo
    glutWireSphere(1.0, 20, 16);
  glPopMatrix();

  // satelite da cor azul
  glPushMatrix();
    // fazer o satelite transladar/orbitar
    glRotatef((GLfloat)ano, 0.0, 1.0, 0.0);
    
    glTranslatef(2.0, 0.0, 0.0);
    
    // Movimento de rotação
    glRotatef((GLfloat)dia, 0.0, 1.0, 0.0);

    // desenho da esfera
    glColor3f(0.0, 0.0, 0.5); // Azul
    glutWireSphere(0.2, 10, 8);
  glPopMatrix();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, w / (h * 1.0), 1.0, 20.0);
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'a':
      dia = (dia + 10) % 360; // controle da rotação
      glutPostRedisplay();
      break;
    case 'd':
      dia = (dia - 10) % 360;
      glutPostRedisplay();
      break;
    case 's':
      ano = (ano + 5) % 360; // controle da translação/órbita
      glutPostRedisplay();
      break;
    case 'w':
      ano = (ano - 5) % 360;
      glutPostRedisplay();
      break;
    case 27: 
      exit(0);
      break;
    default:
      break;
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Sistema Planetario Basico");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glClearColor(1, 1, 1, 1);
  glutMainLoop();
  return 0;
}