#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLdouble pos_carro = 0;
GLdouble rot_rodas = 0;
int cam_view = 0;

void render_floor() {
  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_LINES);
  for (GLfloat i = -100; i <= 100; i += 10) {
    glVertex3f(i, -5, 100);
    glVertex3f(i, -5, -100);
    glVertex3f(100, -5, i);
    glVertex3f(-100, -5, i);
  }
  glEnd();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  render_floor();
  glPushMatrix();
  glTranslatef(pos_carro, 0.0f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);

 
  glPushMatrix();
  glScalef(40, 1, 20);
  glutSolidCube(1);

  glPopMatrix();
  //abre matriz
    glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  //primeira roda dianteira
  glTranslatef(20, 0, 10);
  glRotatef(rot_rodas, 0, 1, 0);
  glutSolidTorus(1.0, 3, 15, 30);
  
  //fecha matriz
    glPopMatrix();
  //segunda roda dianteira
  //abre matriz
    glPushMatrix();
  glTranslatef(20, 0, -10); 
  glRotatef(rot_rodas, 0, 1, 0);
  glutSolidTorus(1.0, 3, 15, 30);
    
  //terceira roda traseira
  glPopMatrix();
  glPushMatrix();
  glTranslatef(25.0, 0, 10);
  glutSolidTorus(1.0, 3, 15, 30);

  //quarta roda traseira
  //fecha matriz
    glPopMatrix();
  //abre matriz
    glPushMatrix();
    glTranslatef(-20, 0, -10);
    glutSolidTorus(1.0, 3, 15, 30);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void change_cam_view() {
  switch (cam_view) {
    case 0:
      gluLookAt(100, 0, 0, 0, 0, 0, 0, 1, 0);
      break;
    case 1:
      gluLookAt(0, 250, 0, 0, 0, 0, 1, 0, 0);
      break;
    case 2:
      gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
      break;
  }
}

void configView() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  glViewport(0, 0, 800, 600);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45, 800 / 600.0, 0.5, 500);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  change_cam_view();

  glDisable(GL_DEPTH_TEST);
}

void resize(GLsizei w, GLsizei h) {
  if (h == 0) h = 1;
}

void specialkeys(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_UP:
      pos_carro += 2;
      break;
    case GLUT_KEY_DOWN:
      pos_carro -= 2;
      break;
    case GLUT_KEY_LEFT:
      rot_rodas -= 5;
      rot_rodas = (rot_rodas < -30) ? -30 : rot_rodas;
      break;
    case GLUT_KEY_RIGHT:
      rot_rodas += 5;
      rot_rodas = (rot_rodas > 30) ? 30 : rot_rodas;
      break;
  }
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;
    case 32:
      cam_view = (++cam_view % 3);
      pos_carro = 0;
      rot_rodas = 0;
      configView();
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Visualizacao 3D");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(specialkeys);
  configView();
  glutMainLoop();
  return 0;
}
