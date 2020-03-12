#include <GL/glew.h>
#include <GL/freeglut.h>
//Flags de compilação : gcc prog01.c -lGL -lGLU -lglut

void drawSquare (int x, int y, float R, float G, float B){
  glColor3f(R, G, B);
  glBegin(GL_POLYGON);
    glVertex2f(x*30,y*30);
    glVertex2f((x*30)+30,y*30);
    glVertex2f((x*30)+30,(y*30)+30);
    glVertex2f(x*30,(y*30)+30);
  glEnd();
  glFlush();
}

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    drawSquare(0 , 0 , 0 , 0 , 0);
    drawSquare(0 , 1 , 1 , 0 , 0);
    drawSquare(0 , 2 , 0 , 1 , 0);
    drawSquare(1 , 0 , 0 , 0 , 1);
    drawSquare(1 , 1 , 1 , 1 , 0);
    drawSquare(1 , 2 , 1 , 0 , 1);
    drawSquare(2 , 0 , 0 , 1 , 1);
    drawSquare(2 , 1 , 1 , 1 , 1);
    drawSquare(2 , 2 , 0.6 , 0.6 , 0.6);
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
    	default:
        	break;
    }
}

// função principal
int main(int argc, char** argv) {
   glutInit(&argc, argv);

   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);

   glutCreateWindow("Disco Floor");
   glutDisplayFunc(drawFunc);
   glutReshapeFunc(reshape);  
   glutKeyboardFunc(keyboard);
   setup();

   glutMainLoop();
   return 0;
}
