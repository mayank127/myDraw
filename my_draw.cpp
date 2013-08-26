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
int mode=0,linepoints=0,polypoints=0;
line_t tempLine;
polygon_t tempPoly;
fill_t tempFill;
//GL reshape callback
void ReshapeGL(int w, int h){
	win_width = w;
	win_height = h;
	glutPostRedisplay();
}

//-------------------------------------------------------------------------

//GL display callback - does all the drawing
GLvoid DisplayGL(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	canvas.drawing.draw(canvas.twoDArray);
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

			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
			gluOrtho2D( 0.0, (GLdouble)w, 0.0, (GLdouble)h);
			glViewport( 0, 0, w, h );

			canvas = canvas_t(drawing_t(), w, h, color_t(r,g,b), pen_t(1, color_t(50,200,0), false));
			cout<<"size"<<canvas.getCurrentPen().getSize()<<endl;
			tempPoly = polygon_t(canvas.getCurrentPen());
			tempPoly.addVertex(point_t(w,0));
			tempPoly.addVertex(point_t(w,h));
			tempPoly.addVertex(point_t(0,h));
			tempPoly.addVertex(point_t(0,0));
			tempPoly.done();
			canvas.drawing.addObject(tempPoly);
			tempFill = fill_t(canvas.getCurrentPen(), point_t(w/2,h/2));
			canvas.drawing.addObject(tempFill);
			glutPostRedisplay();
			break;
		}
		case 'd':
		case 'D'://Initialize a new drawing
			tempLine = line_t();
			tempPoly = polygon_t();
			tempFill = fill_t();
			linepoints = 0;
			polypoints = 0;
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
			if(mode==0)
				mode = 1;
			else if(mode==1)
				mode = 0;
			glutPostRedisplay();
			break;

		case '2'://Toggle Polygon drawing mode
			if(mode==0)
				mode = 2;
			else if(mode==2){
				mode = 0;
				tempPoly.done();
				canvas.drawing.addObject(tempPoly);
				polypoints = 0;
			}
			glutPostRedisplay();
			break;

		case 'f':
		case 'F'://Toggle Fill Mode
			if(mode==0)
				mode = 3;
			else if(mode==3)
				mode=0;

			glutPostRedisplay();
			break;

		case 'c':
		case 'C'://change color
			glutPostRedisplay();
			break;
		default:
			break;
	}
	cout<<"Mode : "<<mode<<endl;
}


void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)	{
		if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
			if(mode==1){
				if ((linepoints % 2 )== 0) {
					linepoints = 0;
					tempLine = line_t(point_t(x,win_height-y), point_t(), canvas.getCurrentPen());
					linepoints++;
				}
				else if ((linepoints % 2) == 1) {
					tempLine.setP2(point_t(x,win_height - y));
					canvas.drawing.addObject(tempLine);
					linepoints++;
				}
				glutPostRedisplay();
			}
			if(mode==2){
				if (polypoints == 0) {
					polypoints++;
					tempPoly = polygon_t(canvas.getCurrentPen());
					tempPoly.addVertex(point_t(x,win_height-y));
				}
				else{
					tempPoly.addVertex(point_t(x,win_height-y));
					polypoints++;
				}
			}
		}
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
	glutMouseFunc(mouse);
	//disabling depth
	glDisable(GL_DEPTH_TEST);
	//Start the GLUT event handling loop
	glutMainLoop();
}

int main(int argc, char** argv)
{
	RenderGL(argc,argv);
}

