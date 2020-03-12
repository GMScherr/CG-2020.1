#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
//Flags de compilação : gcc prog03.c -lGL -lGLU -lglut -lm
//Use shift + '+' para incrementar o número de lados, use '-' para decrementar
//Uma condicional dentro de keyboard() impede o polígono de ter menos que 3 lados

int numberOfSides = 3;

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    float ang = (2*M_PI)/numberOfSides;
    glBegin(GL_TRIANGLE_FAN);
      glVertex2f(0,0);
      for (int i = 0;i<=numberOfSides;i++){
        glVertex2f(cos(ang*i),sin(ang*i));
      }
    glEnd();
    glFlush();

}

void setup() {
    glClearColor(1, 1, 1, 1);
}

void reshape(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-2, 2, -2, 2, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
    	case 27:
        	exit(0);
        	break;
		case 43:
			numberOfSides++;
			break;
		case 45:{
			numberOfSides--;
			if (numberOfSides < 3)
				numberOfSides = 3;
			};
			break;
    	default:
    	    break;
   	 }
	glutPostRedisplay();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);

   glutCreateWindow("Polygon Generator");

   glutDisplayFunc(drawFunc);
   glutReshapeFunc(reshape);  
   glutKeyboardFunc(keyboard);

   setup();

   glutMainLoop();
   return 0;
}
