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
#include <fstream>
#include <sstream>

using namespace std;

int win_width = 1000;
int win_height = 700;
canvas_t canvas;
int mode=0,linepoints=0,polypoints=0;
line_t tempLine;
polygon_t tempPoly;
fill_t tempFill;
point_t tempPoint;
pen_t pen1,pen2;
int type;
bool all = true;
//GL reshape callback
void ReshapeGL(int w, int h){
	win_width = w;
	win_height = h;
	all=true;
	glutPostRedisplay();
}

//-------------------------------------------------------------------------

//GL display callback - does all the drawing
//complete drawing when all is true else only last object is drawn
GLvoid DisplayGL(){
	if(all){
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		canvas.draw();
	}else{
		canvas.drawing.getObjects().back()->draw(canvas.twoDArray);
		all=true;
	}
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
			cout<<"Creating New Canvas..!!"<<endl;
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
			pen1 = pen_t(1, color_t(0,0,0), false);
			pen2 = pen_t(pen1);
			canvas = canvas_t(drawing_t(), w, h, pen_t(1, color_t(r,g,b), true), pen1);
			tempPoly = polygon_t(canvas.getCurrentPen());
			tempPoly.addVertex(point_t(w,0));
			tempPoly.addVertex(point_t(w,h));
			tempPoly.addVertex(point_t(0,h));
			tempPoly.addVertex(point_t(0,0));
			tempPoly.done();
			canvas.drawing.addObject(tempPoly);			//temp polygon of size canvas
			tempFill = fill_t(canvas.getBGColor(), point_t(w/2,h/2));
			canvas.drawing.addObject(tempFill);			//temp fill to fill background
			all=true;
			glutPostRedisplay();
			break;
		}
		case 'd':
		case 'D':
		{//Initialize a new drawing
		//resetting drawing and redrawing canvas
			cout<<"Creating New Drawing..!!"<<endl;
			tempLine = line_t();
			tempPoly = polygon_t();
			tempFill = fill_t();
			linepoints = 0;
			polypoints = 0;
			canvas.setDrawing(drawing_t());
			canvas.clear();
			int w=canvas.getWidth(), h=canvas.getHeight();
			tempPoly = polygon_t(canvas.getCurrentPen());
			tempPoly.addVertex(point_t(w,0));
			tempPoly.addVertex(point_t(w,h));
			tempPoly.addVertex(point_t(0,h));
			tempPoly.addVertex(point_t(0,0));
			tempPoly.done();
			canvas.drawing.addObject(tempPoly);
			tempFill = fill_t(canvas.getBGColor(), point_t(w/2,h/2));
			canvas.drawing.addObject(tempFill);
			all=true;
			glutPostRedisplay();
			break;
		}

		case 's':
		case 'S':
		{//Saving image to images/saveImgae
			fstream fs ("images/saveImage", fstream::out);
			if (fs.is_open()){
				canvas.save(fs);
				fs.close();
				cout<<"File successfully saved as saveImage"<<endl;
			}else{
				cout<<"Error in file"<<endl;
			}
			break;
		}
		case 'l':
		case 'L':
		{//Load image from file
			char filename[100];
			string line;
			cout<<"Input file name: ";
			cin>>filename;
			fstream fs(filename, fstream::in);
			if (fs.is_open()){
				while (fs.good()){
					getline (fs,line);
					stringstream input(line);
					string object;
					input>>object;
					if(object.compare("canvas") == 0){
						cout<<"Loading Canvas..!!"<<endl;
						int w, h, r,g,b;
						input>>w>>h>>r>>g>>b;
						glMatrixMode( GL_PROJECTION );
						glLoadIdentity();
						gluOrtho2D( 0.0, (GLdouble)w, 0.0, (GLdouble)h);
						glViewport( 0, 0, w, h );
						pen1 = pen_t(1, color_t(0,0,0), false);
						pen2 = pen_t(pen1);
						canvas = canvas_t(drawing_t(), w, h, pen_t(1, color_t(r,g,b), true), pen1);
					} else if(object.compare("point")==0){
						cout<<"Loading Point..!!"<<endl;
						int x, y, r, g, b, size, type;
						input>>x>>y>>r>>g>>b>>size>>type;
						tempPoint = point_t(x,y,pen_t(size, color_t(r,g,b), type));
						canvas.drawing.addObject(tempPoint);
					} else if(object.compare("line")==0){
						cout<<"Loading Line..!!"<<endl;
						int x1, y1,x2,y2, r, g, b, size, type;
						input>>x1>>y1>>x2>>y2>>r>>g>>b>>size>>type;
						tempLine = line_t(point_t(x1,y1), point_t(x2,y2), pen_t(size, color_t(r,g,b), type));
						canvas.drawing.addObject(tempLine);
					} else if(object.compare("polygon")==0){
						cout<<"Loading Polygon..!!"<<endl;
						int n, x, y, r, g, b, size, type;
						list <point_t> vertices;
						input>>n;
						for(int i=0; i<n; i++){
							input>>x>>y;
							vertices.push_back(point_t(x,y));
						}
						input>>r>>g>>b>>size>>type;
						tempPoly = polygon_t(vertices, pen_t(size, color_t(r,g,b), type));
						canvas.drawing.addObject(tempPoly);
					} else if(object.compare("fill")==0){
						cout<<"Loading Fill..!!"<<endl;
						int x, y, r1, g1, b1, r2, g2, b2;
						bool type;
						input>>x>>y>>type>>r1>>g1>>b1>>r2>>g2>>b2;
						tempFill = fill_t(pen_t(1, color_t(r1,g1,b1), false), pen_t(1, color_t(r2,g2,b2), false),type ,point_t(x,y));
						canvas.drawing.addObject(tempFill);
					} else if(object.compare("done")==0){
						cout<<"File Reading Successfull..!!"<<endl;
						break;
					} else{
						cout<<"Bug in file..!!Stopping filereading.Image might be damaged"<<endl;
						break;
					}
				}
				fs.close();
			}else{
				cout<<"Error in file reading."<<endl;
			}
			all=true;
			glutPostRedisplay();
			break;
		}

		case '1'://Toggle Line drawing mode
			if(mode==0){
				cout<<"Line Mode Activated!!"<<endl;
				cout<<"\tClick two points to join as line, \n\tUse right click to use erase mode \n\tc to change pen \n\t1 to deactivate line mode"<<endl;
				mode = 1;
			}
			else if(mode==1){
				cout<<"Line Mode Dectivated!!"<<endl;
				mode = 0;
			}
			break;

		case '2'://Toggle Polygon drawing mode
			if(mode==0){
				cout<<"Polygon Mode Activated!!"<<endl;
				cout<<"\tClick points to add to polygon,\n\tUse right click to use erase mode\n\tc to change pen \n\t2 to draw polygon"<<endl;
				mode = 2;
			}
			else if(mode==2){
				mode = 0;
				tempPoly.done();
				canvas.drawing.addObject(tempPoly);
				polypoints = 0;
				cout<<"Polygon Drawn!!"<<endl;
				cout<<"Polygon Mode Deactivated!!"<<endl;
			}
			all=false;
			glutPostRedisplay();
			break;

		case 'f':
		case 'F'://Toggle Fill Mode
			if(mode==0){
				cout<<"Fill Mode Activated!!"<<endl;
				cout<<"\tClick points to fill bounded region as line,\n\tUse right click to use erase mode \n\tc to change pen and type of fill \n\tf to deactivate line mode"<<endl;
				mode = 3;
			}
			else if(mode==3){
				cout<<"Fill Mode Deactivated!!"<<endl;
				mode=0;
			}
			break;

		case 'c':
		case 'C':
			{//change pen color
				int r,g,b,size;
				if(mode==3){
					type =0;
					cout<<"Type of fill (0:Normal, 1:Checkboard): ";
					cin>>type;
					if(type==0){
						cout<<"Enter Pen Color (RGB) :";
						cin>>r>>g>>b;
						pen1 = pen_t(1, color_t(r,g,b), false);
					}else{
						cout<<"Enter Pen 1 Color (RGB) :";
						cin>>r>>g>>b;
						pen1 = pen_t(1, color_t(r,g,b), false);
						cout<<"Enter Pen 2 Color (RGB) :";
						cin>>r>>g>>b;
						pen2 = pen_t(1, color_t(r,g,b), false);
					}
				}else{
					cout<<"Enter Pen Color (RGB) :";
					cin>>r>>g>>b;
					cout<<"Enter Pen Size :";
					cin>>size;
					pen1 = pen_t(size, color_t(r,g,b), false);
					canvas.setCurrentPen(pen1);
					pen_t tempPen = pen_t(canvas.getBGColor());
					tempPen.setSize(size);
					canvas.setBGColor(tempPen);
				}
			}
			break;
		case 'u':
		case 'U'://Undo
				cout<<"Undo Last Drawn Object"<<endl;
				canvas.drawing.removeLastObject();
			all=true;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}


void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)	{
		if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
			if(mode==1){
				if ((linepoints % 2 )== 0) {
					linepoints = 0;
					if(button == GLUT_LEFT_BUTTON)
						tempLine = line_t(point_t(x,win_height-y), point_t(), canvas.getCurrentPen());
					else
						tempLine = line_t(point_t(x,win_height-y), point_t(), canvas.getBGColor());
					linepoints++;
				}
				else if ((linepoints % 2) == 1) {
					tempLine.setP2(point_t(x,win_height - y));
					canvas.drawing.addObject(tempLine);
					cout<<"Line Drawn!!"<<endl;
					linepoints++;
				}
				all=false;
				glutPostRedisplay();
			}
			if(mode==2){
				if (polypoints == 0) {
					polypoints++;
					if(button == GLUT_LEFT_BUTTON)
						tempPoly = polygon_t(canvas.getCurrentPen());
					else
						tempPoly = polygon_t(canvas.getBGColor());
					tempPoly.addVertex(point_t(x,win_height-y));
				}
				else{
					tempPoly.addVertex(point_t(x,win_height-y));
					polypoints++;
				}
			}
			if(mode==3){
				if(button == GLUT_LEFT_BUTTON){
					if(type==0){
						tempFill = fill_t(pen1, point_t(x,win_height-y));
					}else{
						tempFill = fill_t(pen1, pen2, true, point_t(x,win_height-y));
					}
				}
				else
					tempFill = fill_t(canvas.getBGColor(), point_t(x,win_height-y));

				canvas.drawing.addObject(tempFill);
				cout<<"Fill Drawn!!"<<endl;
				all=false;
				glutPostRedisplay();
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

