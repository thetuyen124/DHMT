#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>

static GLfloat spin = 0.0;
float zoom = 4;
float tX = 0, tY = 0, tZ = -8, rX = 0, rY = 0, rZ = 4;
float rotX = 0, rotY = 0, rotZ = 0;
float space = 0.0;
float fracx = 0;
float fracy = 0;

bool rot = false;



void mouse(int button, int state, int x, int y);
void plane();
void draw();
static void key(unsigned char key, int x, int y);



void init(void)
{
	glClearColor(0.5, 0.5, 1.0, 1.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0.0, 4.5, 10.0,
		0, 4, 0,
		0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glScaled(zoom, zoom, zoom);
	glRotated(spin, 1, 0, 0);

	glTranslatef(tX, tY, space);
	draw();
	glPopMatrix();
	glutSwapBuffers();
	
}
void fly(void)
{
	if (space < -20||tX>5 ||tX<-5)
	{
		tX = 0;
		tY = 0;
		rotX = 0;
		rotY = 0;
		rotZ = 0;
		space = 0;
		fracx = 0;
		fracy = 0;
	}
	else {
		space -= 0.001;
		tX += fracx;
		tY += fracy;
	}

	glutPostRedisplay();
}
void reshape(int w, int h)
{
	const float ar = (float)w / (float)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(fly);
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
		{
			tX = 0;
			tY = 0;
			rotX = 0;
			rotY = 0;
			rotZ = 0;
			space = 0;
			fracx = 0;
			fracy = 0;
		}
		break;
	default:
		break;
	}
}
/* Request double buffer display mode.
Register mouse input callback functions */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(400, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(fly);
	glutKeyboardFunc(key);
	glutMouseFunc(mouse);
	glutMainLoop();
}



void plane() {

	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double a = t * 90.0;

	/// Main body
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslated(0, 0, 0);
	glScaled(3, 0.4, 0.5);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glColor3d(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslated(1.7, 0.1, 0);
	glScaled(1.5, 0.7, 0.8);
	glRotated(40, 0, 1, 0);
	glutSolidSphere(0.45, 30, 30);
	glPopMatrix();

	///Samner Pakha

	///Right
	glColor3f(0.8, 1, 0);
	glPushMatrix();
	glTranslated(0, 0, 1.2);
	glRotated(-50, 0, 1, 0);
	glScaled(0.7, 0.1, 3);
	glRotated(25, 0, 1, 0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(-0.3, -0.15, 1.5);
	glRotated(90, 0, 1, 0);
	glScaled(0.1, 0.1, 0.9);
	glutSolidTorus(0.5, 0.5, 50, 50);
	glPopMatrix();

	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(0.2, -0.15, 0.9);
	glRotated(90, 0, 1, 0);

	/// FAN
	//        glPushMatrix();
	//            glTranslated(0,0,0.5);
	//            glRotated(10*a,0,0,1);
	//            glScaled(0.1,0.1,0.1);
	//            fan();
	//        glPopMatrix();

	glScaled(0.1, 0.1, 0.9);
	glutSolidTorus(0.5, 0.5, 50, 50);
	glPopMatrix();

	///Left
	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(0, 0, -1.2);
	glRotated(50, 0, 1, 0);
	glScaled(0.7, 0.1, 3);
	glRotated(-25, 0, 1, 0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(-0.3, -0.15, -1.5);
	glRotated(90, 0, 1, 0);
	glScaled(0.1, 0.1, 0.9);
	glutSolidTorus(0.5, 0.5, 50, 50);
	glPopMatrix();

	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(0.2, -0.15, -0.9);
	glRotated(90, 0, 1, 0);
	glScaled(0.1, 0.1, 0.9);
	glutSolidTorus(0.5, 0.5, 50, 50);
	glPopMatrix();


	///Pechoner pakha
	glPushMatrix();
	glTranslated(-2.8, 0, 0);
	glScaled(0.8, 0.5, 0.3);

	///Right
	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(0.4, 0, 1.5);
	glRotated(-30, 0, 1, 0);
	glScaled(0.7, 0.1, 3);
	glRotated(10, 0, 1, 0);
	glutSolidCube(1);
	glPopMatrix();

	///left
	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(0.4, 0, -1.5);
	glRotated(30, 0, 1, 0);
	glScaled(0.7, 0.1, 3);
	glRotated(-10, 0, 1, 0);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	/// Pesoner Uporer pakha
	glColor3d(0.8, 1, 0);
	glPushMatrix();
	glTranslated(-2.7, 0.5, 0);
	glRotated(45, 0, 0, 1);
	glScaled(0.8, 2, 0.1);
	glRotated(-20, 0, 0, 1);
	glutSolidCube(0.5);
	glPopMatrix();

	//    glColor3d(0.8,1,0);
	//    glPushMatrix();
	//        glTranslated(-2.95,0.85,0);
	//        glRotated(90,0,1,0);
	//        glScaled(0.05,0.05,0.6);
	//        glutSolidTorus(0.5,0.5,50,50);
	//    glPopMatrix();


		///FANS

	//    glPushMatrix();
	//        glTranslated(0,0,0);
	//        glRotated(10*a,0,0,1);
	//        //glRotated(90,1,0,0);
	//        fan();
	//    glPopMatrix();
}

void draw() {
	if (rotX > 12) {
		rotX = 12;
		fracx = 0.0004;
	}
	if (rotX < -12) {
		rotX = -12;
		fracx = -0.0004;
	}
	if (rotY < -2) {
		rotY = -2;
	}
	if (rotY > 2) {
		rotY = 2;
	}
	if (rotZ > 10) {
		rotZ = 10;
		fracy = 0.001;
	}
	if (rotZ < -15) {
		rotZ = -15;
		fracy = -0.001;
	}
		glPushMatrix();
		glTranslated(0, 1, 0);
		glRotated(90, 0, 1, 0);
		glRotated(5, 0, 0, 1);
		glRotated(rotX, 1, 0, 0);
		glRotated(rotY, 0, 1, 0);
		glRotated(rotZ, 0, 0, 1);

		glScaled(0.4, 0.4, 0.4);
		plane();
		glPopMatrix();
}

static void key(unsigned char key, int x, int y)
{
	float rotFrac = 1;
	switch (key)
	{
	case 27:
	case 'q':
		exit(0);
		break;
	case 'w':
		fracy += 0.0001;
		rotZ += rotFrac;
		break;
	case 's':
		fracy-= 0.0001;
		rotZ -= rotFrac;
		break;
	case 'a':
		fracx -= 0.0001;
		rotX -= rotFrac * 3;
		rotY += rotFrac / 2;
		break;
	case 'd':
		fracx += 0.0001;
		rotX += rotFrac * 3;
		rotY -= rotFrac / 2;
		break;
	}

	glutPostRedisplay();
}