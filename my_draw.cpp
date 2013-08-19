#include <cstdlib>
#include <GL/glut.h>
#include "my_draw.h"
#include <iostream>
using namespace std;

int win_width = 1000;
int win_height = 700;

//GL reshape callback
void ReshapeGL(int w, int h){
  if  ( h == 0 ) h = 1;

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho(0, w, h, 0, 0, 1.0);

  win_width = w;
  win_height = h;

  glutPostRedisplay();
}

//-------------------------------------------------------------------------

//GL display callback - does all the drawing
GLvoid DisplayGL(){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  //draw here
  glFlush();
}

//-------------------------------------------------------------------------

//GL keyboard callback
GLvoid KeyPressedGL(unsigned char key, GLint x, GLint y){
  switch (key)
  {
	  //quit
    case ESCAPE: exit(1);
	    break;
    case 'n' :
    case 'N' : cout<<"n";
   		//Initialize a new canvas
      glutPostRedisplay();
		  break;

    case 'd' :
    case 'D' ://Initialize a new drawing
	    glutPostRedisplay();
		  break;

    case 's':
    case 'S'://Save
      glutPostRedisplay();
      break;

    case 'l':
    case 'L'://Load
	    glutPostRedisplay();
		  break;

    case '1'://Toggle Line drawing mode
	    glutPostRedisplay();
		  break;

    case '2'://Toggle Polygon drawing mode
	    glutPostRedisplay();
		  break;

    case 'f':
    case 'F'://Toggle Fill Mode
	    glutPostRedisplay();
		  break;

    case 'c':
    case 'C'://change color
	    glutPostRedisplay();
		  break;
    default:
		  break;
  }
}

// The main rendering function
GLvoid RenderGL(int argc, char** argv)
{
  //Initialize GLUT
  glutInit(&argc, argv);
  //Initialize GLUT display
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  //Window top-left corner position
  glutInitWindowPosition(0,0);
  //Window size
  glutInitWindowSize(win_width, win_height);
  //Window title
  glutCreateWindow("My Draw");

  //Register the callbacks
  glutDisplayFunc(&DisplayGL);
  glutReshapeFunc(&ReshapeGL);
  glutKeyboardFunc(&KeyPressedGL);

  //disabling depth
  glDisable(GL_DEPTH_TEST);
  //Start the GLUT event handling loop
  glutMainLoop();
}

int main(int argc, char** argv)
{
  RenderGL(argc,argv);
}
