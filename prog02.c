#include <GL/glew.h>    
#include <GL/freeglut.h>
//Flags de compilação : gcc prog02.c -lGL -lGLU -lglut
//'G' e 'g' para alternar entre com ou sem contorno
void drawSquareDisc(){
	glBegin(GL_TRIANGLE_STRIP);
      glVertex2f(0   ,0 );
      glVertex2f(15 ,75 );
      glVertex2f(0  ,90 );
      glVertex2f(75 ,75 );
      glVertex2f(90 ,90 );
      glVertex2f(75 ,15 );
      glVertex2f(90  ,0 );
      glVertex2f(15 ,15 );
      glVertex2f(0   ,0 );
      glVertex2f(15 ,75 );
    glEnd();
    glFlush();
}

void lines (){
  glColor3f(1, 1, 1);
    drawSquareDisc();
}

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);
	drawSquareDisc();
}

void setup() {
    glClearColor(1, 1, 1, 1);
}

void reshape(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 90, 0, 90, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
    	case 27:
        	exit(0);
        	break;
    	case 'g':{
        	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
       	 	lines();
      	}
      	 	break;
    	case 'G':{
    	    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    	    glutPostRedisplay();
    	  }
    	  	break;
   	 default:
   	     	break;
    }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);

   glutCreateWindow("Hollow Square");

   glutDisplayFunc(drawFunc);
   glutReshapeFunc(reshape);  
   glutKeyboardFunc(keyboard);

   setup();

   glutMainLoop();
   return 0;
}
