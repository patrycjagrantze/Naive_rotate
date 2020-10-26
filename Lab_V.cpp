//Grantze Patrycja
//nr albumu 167767
//Algorytm naiwnego obracania kostki za pomoca myszki


#include <windows.h>  
#include <GL/glut.h>  
#include <string>


char title[] = "Cube 3D";
double rot_x = 0, rot_y = 0, rot_z = 0;
GLfloat angle = 0.0;
GLfloat lx = 0.0, lz = 1.0;
float winWid, winHeight;


int px, py;

//ustawienia myszy, jej pozycja, ustalanie kąta
void set_pos(int& x, int& y)
{
    px = x;
    py = y;
}


void motion(int x, int y)

{
    printf("Key %c, pos(X: %d, Y: %d)\n", x, y);
    rot_x += (x - px) * 0.1;
    rot_y += (y - py) * 0.1;
    if (rot_x > 360)
    {
        rot_x -= 360;
    }
    if (rot_x < -360)
    {
        rot_x += 360;
    }
    if (rot_y > 360)
    {
        rot_y -= 360;
    }
    if (rot_y < -360)
    {
        rot_y += 360;
    }

}

void mousebutton(int button, int state,
    int x, int y)
{

    if (button == 0 && state == 0)
    {
        set_pos(x, y);
        return;
    }
    if (button == 0 && state == 1)
    {
        motion(x, y);


    }
    glutPostRedisplay();

}





void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);


    glLoadIdentity();
    gluLookAt(lx * 5.0, 0, lz * 5.0,
        0, 0, 0,
        0.0, 1.0, 0.0);
    glTranslatef(1.5f, 0.0f, -7.0f);
    glPushMatrix();
    glRotatef(rot_y, 1, 0, 0);
    glRotatef(rot_x, 0, 1, 0);
    glBegin(GL_QUADS);
    // Top face (y = 0.5f)
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    // Bottom face (y = -0.5f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    // Front face  (z = 0.5f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // Back face (z = -0.5f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    // Left face (x = -0.5f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    // Right face (x = 0.5f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();


    glutSwapBuffers();
}


void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}








int main(int argc, char** argv) {
    winWid = 640.0;
    winHeight = 480.0;
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMotionFunc(motion);
    glutMouseFunc(mousebutton);
    glutMainLoop();
    return 0;
}