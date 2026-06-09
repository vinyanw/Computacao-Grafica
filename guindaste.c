#include <GL/glut.h>
#include <stdlib.h>

float angBracoPrincipal = 0;
float angBracoSecundario = 0;
float altGancho = 0;
int cam_view = 0;

void change_cam_view() {
  switch (cam_view) {
    case 0:
      gluLookAt(40, 30, 40, 0, 0, 0, 0, 1, 0);
      break;
    default:
      gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);
      break;
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Uma câmera levemente inclinada ajuda a ver o modelo 3D melhor
    gluLookAt(20, 20, 40, 0, 5, 0, 0, 1, 0);

    // --- BASE ---
    glPushMatrix();
    {
      glColor3f(0.0f, 0.0f, 0.0f);
      glScalef(6, 1, 6);
      glutSolidCube(1);
    }
    glPopMatrix();

    // --- PILAR (POSTE) ---
    glPushMatrix();
    {
      glTranslatef(0, 6, 0);
      glScalef(4, 12, 4);
      glColor3f(1.0f, 1.0f, 0.0f);
      glutSolidCube(1);
    }
    glPopMatrix();    

    // ESTRUTURA ARTICULADA
    // Movemos para o topo do pilar para começar a desenhar os braços
    glPushMatrix();
    {
      glTranslatef(0, 12, 0); 
      glRotatef(angBracoPrincipal, 0, 1, 0); // Gira o braço principal em torno do eixo Y (Q e E)

      // Braço principal
      glPushMatrix();
      {
        glTranslatef(6, 0, 0); // Move a "massa" do braço para frente do pivô
        glScalef(12, 2, 2);
        glColor3f(0.8f, 1.0f, 0.0f);
        glutSolidCube(1);
      }
      glPopMatrix();

      // Avança para a ponta do braço principal para conectar o secundário
      glPushMatrix();
      {
        glTranslatef(12, 0, 0); 
        glRotatef(angBracoSecundario, 0, 1, 0); // Gira o braço secundário em torno do eixo Y (A e D)

        // Braço secundário
        glPushMatrix();
        {
          glTranslatef(3, 0, 0); 
          glScalef(6, 1.5, 1.5);
          glColor3f(0.4f, 1.0f, 0.0f);
          glutSolidCube(1);
        }
        glPopMatrix();  

        // Avança para a ponta do braço secundário para pendurar o gancho
        glPushMatrix();
        {
          glTranslatef(6, 0, 0);
          
          // Cabo/Gancho (sobe e desce com W e S afetando altGancho)
          // O gancho desce no eixo Y negativo
          glPushMatrix();
          {
            glTranslatef(0, -2 + altGancho, 0); 
            glScalef(0.5, 4, 0.5);
            glColor3f(0.6f, 0.6f, 0.6f);
            glutSolidCube(1);
          }
          glPopMatrix();

          // Ponta do Gancho
          glPushMatrix();
          {
            glTranslatef(0, -4 + altGancho, 0);
            glScalef(1, 1, 1);
            glColor3f(1.0f, 0.0f, 0.0f);
            glutSolidCube(1);
          }
          glPopMatrix();
        }
        glPopMatrix(); // Fim do Gancho
      }
      glPopMatrix(); // Fim do Braço Secundário
    }
    glPopMatrix(); // Fim do Braço Principal

    glutSwapBuffers();
}

void configView() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glViewport(0, 0, 800, 600);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 800.0 / 600.0, 0.5, 500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
  // O switch aceita tanto maiúsculas quanto minúsculas
  switch (key) {
    case 27: // ESC
      exit(0);
      break;
    
    // Braço Principal (Q gira anti-horário, E gira horário)
    case 'q': case 'Q':
      angBracoPrincipal += 5.0f;
      break;
    case 'e': case 'E':
      angBracoPrincipal -= 5.0f;
      break;

    // Braço Secundário (A gira anti-horário, D gira horário)
    case 'a': case 'A':
      angBracoSecundario += 5.0f;
      break;
    case 'd': case 'D':
      angBracoSecundario -= 5.0f;
      break;

    // Gancho (W sobe, S desce)
    case 'w': case 'W':
      altGancho += 0.5f;
      if (altGancho > 2.0f) altGancho = 2.0f; // Limite para não subir demais
      break;
    case 's': case 'S':
      altGancho -= 0.5f;
      if (altGancho < -6.0f) altGancho = -6.0f; // Limite para não cair no chão
      break;

    // Resetar posições
    case 'r': case 'R':
      angBracoPrincipal = 0.0f;
      angBracoSecundario = 0.0f;
      altGancho = 0.0f;
      break;

    default:
      break;
  }
  glutPostRedisplay(); // Redesenha a tela após a atualização das variáveis
}

void init(void) {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
}

void update(int value) {
  glutPostRedisplay();
  glutTimerFunc(16, update, 0); // ~60 frames por segundo (16ms) em vez de 1000ms
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Guindaste Articulado");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  configView();
  init();
  glutTimerFunc(0, update, 0);
  glutMainLoop();
  return 0;
}