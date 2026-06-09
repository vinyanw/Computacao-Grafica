#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat fAspect;
GLdouble rotX = 0, rotY = 0, rotHead = 0, rotBlade = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);

	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);

	glColor3f(1.0f, 0.0f, 0.0f);

	// Base
	glPushMatrix();
	{
		glTranslatef(0.0f, -10.0f, 0.0f);
		glScalef(10, 2, 10);
		glutWireCube(1);
	}
	glPopMatrix();

	// Haste
	glPushMatrix();
	{
		glTranslatef(0.0f, -4.0f, 0.0f);
		glScalef(2, 10, 2);
		glutWireCube(1);
	}
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 1.0f);

	// Abrir estrutura de matriz
	glPushMatrix();
	glTranslatef(0.0f, 3.0f, 0.0);
	glRotatef(rotHead, 0, 1, 0);
	// Motor
	glPushMatrix();
	{
	glScalef(4, 4, 6);
	glutWireCube(1);
	}
	glPopMatrix();

	// Ponta
	glPushMatrix();
	{
	glTranslatef(0.0f, 0.0f, 3.0f);
	glutSolidSphere(0.5, 10, 8);
	}
	glPopMatrix();

	glColor3f(0.0f, 1.0f, 0.0f);

	glTranslatef(0.0f, 0.0f, 3.0f);
	glRotatef(rotBlade, 0, 0, 1);
	// Hélice
	glPushMatrix();
	{
		glScalef(16, 2, 1);
		glutWireCube(1);
	}
	glPopMatrix();
	// Hélice
	glPushMatrix();
	{
		glScalef(2, 16, 1);
		glutWireCube(1);
	}
	glPopMatrix();

	//Fechando estrutura de matriz
	glPopMatrix();
	glutSwapBuffers();
}

void configProjection(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, fAspect, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);
}

void resize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	fAspect = (GLfloat)w / (GLfloat)h;

	configProjection();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'z':
		rotHead += 10;
		break;
	case 'x':
		rotBlade += 10;
	case 27:
		exit(0);
		break;
	case 32:
		rotX = 0;
		rotY = 0;
		rotHead+=3;
		rotBlade+=6;
	
	default:
		break;
	}

	glutPostRedisplay();
}

void specialkeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		rotX += 10;
		break;
	case GLUT_KEY_DOWN:
		rotX += 10;
		break;
	case GLUT_KEY_LEFT:
		rotY += 10;
		break;
	case GLUT_KEY_RIGHT:
		rotY -= 10;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Avaliação 02");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	//glutSpecialFunc(specialkeys);
	glutMainLoop();
	return 0;
}
