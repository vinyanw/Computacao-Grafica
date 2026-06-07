#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>
#include <time.h>

int cam_view = 0;
float hourAngle, minuteAngle, secondAngle;

void drawClockFace() {
  glColor3f(0.2f, 0.2f, 0.2f);

  // marcações das horas
  for (int i = 0; i < 12; ++i) {
    glPushMatrix();
    float angle = i * 30.0f;
    glRotatef(angle, 0, 1, 0);
    glTranslatef(25, 0, 0);
    glScalef(1.5, 1, 1);
    glutSolidCube(1);
    glPopMatrix();
  }
}

void updateTimeAngles() {
  time_t rawTime;
  struct tm *timeInfo;
  time(&rawTime);
  timeInfo = localtime(&rawTime);

  int hours = timeInfo->tm_hour;
  int minutes = timeInfo->tm_min;
  int seconds = timeInfo->tm_sec;

  hourAngle = -((hours % 12 + minutes / 60.0f) * 30.0f);
  minuteAngle = -(minutes * 6.0f);
  secondAngle = -(seconds * 6.0f);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  updateTimeAngles();

  drawClockFace();

  glPushMatrix();
  {
    glRotatef(90, 90, 0, 0);
    glutSolidTorus(1, 30, 30, 100);
  }
  glPopMatrix();
  glPushMatrix();
  {
    //cor azul do ponteiro de hora
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(hourAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(8.0f, 0.0f, 0.0f);
    glScalef(16, 1, 1);
    glutSolidCube(1);
  }
  glPopMatrix();

  glPushMatrix();
  {
    //cor verde do ponteiro de minuto
    glColor3f(0.0f, 1.0f, 0.0f);
    glRotatef(minuteAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(12.0f, 0.0f, 0.0f);
    glScalef(24, 1, 1);
    glutSolidCube(1);
  }
  glPopMatrix();

  glPushMatrix();
  {
    //cor vermelho do ponteiro de segundo
    glColor3f(1.0f, 0.0f, 0.0f);
    glRotatef(secondAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef( 25.0f, 0.0f, 0.0f);
    glScalef(2, 1, 1);
    glutSolidCube(1);
  }
  glPopMatrix(); 

  glutSwapBuffers();
}

void change_cam_view() {
  switch (cam_view) {
    case 0:
      gluLookAt(0, 100, 0, 0, 0, 0, 1, 0, 0);
      break;
    case 1:
      gluLookAt(-100, 50, 0, 0, 0, 0, 1, 0, 0);
      break;
    case 2:
      gluLookAt(-50, 50, 50, 0, 0, 0, 0, 1, 0);
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
}

void resize(GLsizei w, GLsizei h) {
  if (h == 0) h = 1;
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;
    case 32:
      cam_view = (++cam_view % 3);
      configView();
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void init(void) {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
}

void update(int value) {
  glutPostRedisplay();
  glutTimerFunc(1000, update, 0);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Relogio Analogico 3D");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  init();
  glutTimerFunc(0, update, 0);
  glutMainLoop();
  return 0;
}
