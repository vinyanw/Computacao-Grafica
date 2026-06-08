#include <GL/glut.h>

float angHelice = 0;
int cam_view = 0;

void change_cam_view() {
  switch (cam_view) {
    case 0:
      //gluLookAt(0, 100, 0, 0, 0, 0, 1, 0, 0);
      gluLookAt(40, 30, 40, 0, 0, 0, 0, 1, 0);
      break;
    case 1:
      //gluLookAt(-100, 50, 0, 0, 0, 0, 1, 0, 0);
      break;
    case 2:
      //gluLookAt(-50, 50, 50, 0, 0, 0, 0, 1, 0);
      break;
  }
}

void drawHelice() {
  glPushMatrix();
  // Centro da hélice
  glColor3f(0, 0, 0);
  glutSolidSphere(0.8, 20, 20);
  // 4 pás
  for(int i = 0; i < 4; i++) {
    glPushMatrix();
    glRotatef(i * 90, 0, 0, 1);
    // desloca a pá para longe do centro
    glTranslatef(0, 4, 0);
    glColor3f(1, 1, 1);

    glPushMatrix();
      glScalef(0.8, 8, 0.4);
      glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
    }

    glPopMatrix();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //change_cam_view();   
    gluLookAt(50, 0, 50, 0, 0, 0, 0, 1, 0);

    
    glPushMatrix();
    {
        glScalef(6, 20, 6);
        glColor3f(1.0f, 0.0f, 0.0f);
        glutSolidCube(1);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0, 8, 3);
        glRotatef(angHelice, 0, 0, -1);
        drawHelice();
    }
    glPopMatrix();


    glutSwapBuffers();
}

void configView() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glViewport(0, 0, 800, 600);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 800 / 600.0, 0.5, 500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // change_cam_view();
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
      //cam_view = (++cam_view % 3);
      //configView();
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void init(void) {
  glClearColor(0, 0, 0, 1.0f);
  glEnable(GL_DEPTH_TEST);
}

void update(int value) {
  angHelice+=25;
  glutPostRedisplay();
  glutTimerFunc(1000, update, 0);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Moinho");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  init();
  glutTimerFunc(0, update, 0);
  glutMainLoop();
  return 0;
}