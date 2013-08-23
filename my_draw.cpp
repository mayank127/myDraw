#include <cstdlib>
#include <GL/glut.h>
#include "my_draw.h"
#include <iostream>
#include "color_t.h"
#include "pen_t.h"
#include "object_t.h"
#include "fill_t.h"
#include "point_t.h"
#include "line_t.h"
#include "polygon_t.h"
#include "drawing_t.h"
#include "canvas_t.h"

using namespace std;

int win_width = 500;
int win_height = 500;
canvas_t canvas;
//GL reshape callback
void ReshapeGL(int w, int h){
	if(h == 0) h = 1;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0.0, (GLdouble)w, 0.0, (GLdouble)h);

	win_width = w;
	win_height = h;

	glutPostRedisplay();
}

//-------------------------------------------------------------------------

//GL display callback - does all the drawing
GLvoid DisplayGL(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	pen_t tempPen = pen_t(20,color_t(255,255,255),false);
	polygon_t tempPoly = polygon_t(tempPen);
	tempPoly.addVertex(point_t(400,0,tempPen));
	tempPoly.addVertex(point_t(400,400,tempPen));
	tempPoly.addVertex(point_t(0,400,tempPen));
	tempPoly.addVertex(point_t(0,0,tempPen));
	tempPoly.addVertex(point_t(400,0,tempPen));
	tempPoly.draw();
	canvas.getDrawing().draw();
	glFlush();
}

//-------------------------------------------------------------------------

//GL keyboard callback
GLvoid KeyPressedGL(unsigned char key, GLint x, GLint y){
	switch (key){
		//quit
		case ESCAPE:
			exit(1);
			break;
		case 'n':
		case 'N':
		{	//Initialize a new canvas
			int w,h;
			cout<<"Enter width : ";
			cin>>w;
			cout<<"Enter Height : ";
			cin>>h;
			int r,g,b;
			cout<<"Enter RGB for background (0 - 255): ";
			cin>>r>>g>>b;

			glViewport( 0, 0, w, h );

			canvas = canvas_t(w,h,color_t(r,g,b));
			glutPostRedisplay();
			break;
		}
		case 'd':
		case 'D'://Initialize a new drawing
			canvas.setDrawing(drawing_t());
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
GLvoid RenderGL(int argc, char** argv){
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

