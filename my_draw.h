#ifndef MY_DRAW_H
#define MY_DRAW_H
// Defining the ESCAPE Key Code
#define ESCAPE 27
// Defining the DELETE Key Code
#define DELETE 127

GLvoid InitGL();
GLvoid ReshapeGL (GLsizei Width, GLsizei Height);
GLvoid DisplayGL();
GLvoid KeyPressedGL(unsigned char key, GLint x, GLint y);
GLvoid RenderGL(int argc, char** argv);
void mouse(int button, int state, int x, int y);
#endif
