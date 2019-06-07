#include "libs.h"


GLfloat xRotated, yRotated, zRotated;
GLfloat xRotated2, yRotated2, zRotated2;
GLdouble radius = 1;
bool xFlag = false, yFlag = false, zFlag = false, discoFlag = false, orbitFlag = false;
float color1 = 1.0f;
float color2 = 1.0f;
float color3 = 1.0f;

float discoColors1 = 0.0f;
float discoColors2 = 0.0f;
float discoColors3 = 0.0f;

void NormalKeyHandler(unsigned char key, int x, int y)
{
	if (key == 'x')
	{
		xFlag = true;
		yFlag = false;
		zFlag = false;
	}
	else if (key == 'y')
	{
		xFlag = false;
		yFlag = true;
		zFlag = false;
	}
	else if (key == 'z')
	{
		xFlag = false;
		yFlag = false;
		zFlag = true;
	}
	else if (key == 'r')
	{
		color1 = 0.647; color2 = 0.165; color3 = 0.165;
	}
	else if (key == 'g')
	{
		color1 = 0.125; color2 = 0.698; color3 = 0.667;
	}
	else if (key == 'd')
	{
		discoFlag = true;
	}
	else if (key == 'o')
	{
		zRotated2 += 0.01;
	}
	else if (key == 'p')
	{
		yRotated2 += 0.01;
	}

}

void timer(int value)
{
	discoColors1 += 0.001f;
	discoColors2 += 0.003f;
	discoColors3 += discoColors2;
	if (discoColors1 > 1.0)
		discoColors1 = 0;
	if (discoColors2 > 1.0)
		discoColors2 = 0;
	if (discoColors3 > 1.0)
		discoColors3 = 0;

	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void redisplayFunc(void)
{

	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(0.0, 0.0, -8.5);
	// Red color used to draw.
	if (discoFlag)
		glColor3f(discoColors3, discoColors1, discoColors2);
	else
		glColor3f(color3, color1, color2);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(0.5, 10, 10);
	// Flush buffers to screen

	glTranslatef(0.0, 0.0, -4.5 + zRotated2);
	//color used to draw.
	if (discoFlag)
		glColor3f(discoColors3, discoColors1, discoColors2);
	else
		glColor3f(color3, color1, color2);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated2, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated2, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated2, 0.0, 0.0, 1.0);
	// scaling transfomation
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(0.5, 12, 12);

	glTranslatef(0.0, 0.0, -4.5 + yRotated2);
	//color used to draw.
	if (discoFlag)
		glColor3f(discoColors3, discoColors1, discoColors2);
	else
		glColor3f(color3, color1, color2);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated2, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated2, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated2, 0.0, 0.0, 1.0);
	// scaling transfomation
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(0.5, 14, 10);


	// swap buffers called because we are using double buffering 
	glutSwapBuffers();
	glFlush();
}

void reshapeFunc(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Angle of view:40 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}


void idleFunc(void)
{
	if (yFlag)
		yRotated += 0.01;
	else if (xFlag)
		xRotated += 0.01;
	else if (zFlag)
		zRotated += 0.01;

	redisplayFunc();
}


int main(int argc, char **argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	//double buffering used to avoid flickering problem in animation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// window size
	glutInitWindowSize(1200, 1000);
	// create the window 
	glutCreateWindow("Disco Planets");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glutKeyboardFunc(NormalKeyHandler);
	xRotated = yRotated = zRotated = 30.0;
	xRotated = 33;
	yRotated = 40;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//Assign  the function used in events
	glutDisplayFunc(redisplayFunc);
	glutTimerFunc(0, timer, 0);
	glutReshapeFunc(reshapeFunc);

	glutIdleFunc(idleFunc);
	//Let start glut loop
	glutMainLoop();
	return 0;
}

