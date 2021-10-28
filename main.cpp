/*
3D Classroom Design
Faisal Ahmed
Roll: 1607048
*/


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<iostream>
using namespace std;

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1000, windowWidth=800;
GLfloat theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;



static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},
    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte quadIndices[6][4] =
{
    {3, 1, 5, 7},
    {2, 0, 4, 6},
    {2, 0, 1, 3},
    {6, 4, 5, 7},
    {2, 3, 7, 6},
    {0, 1, 5, 4}
};

void cube(float color_red = 0.5, float color_green = 0.5, float color_blue = 0.5)
{
    glBegin(GL_QUADS);
    for(GLint i = 0; i<6; i++)
    {
        glColor3f(color_red,color_green,color_blue);

        for(GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[quadIndices[i][j]][0]);
        }
    }
    glEnd();
}

void axes()
{
    float length = 10;
    float width = 1;

    // x-axis
    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,width,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1.0,0.1,0.1);
    glPopMatrix();

    // y-axis
    glPushMatrix();
    glTranslatef(0,length/2,0);
    glScalef(width,length,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.1,1.0,0.1);
    glPopMatrix();

    // z-axis
    glPushMatrix();
    glTranslatef(0,0,length/2);
    glScalef(width,width,length);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.1,0.1,1.0);
    glPopMatrix();
}


void function_K()
{

    //base
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(5,40,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1.0,0.0,0.0);
    glPopMatrix();

    // upper line
     glPushMatrix();
    glTranslatef(10,5,0);
    glRotatef(60,0,0,1);
    glScalef(30,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1.0,0.0,0.0);
    glPopMatrix();

    // lower line
    glPushMatrix();
    glTranslatef(10,-5,0);
    glRotatef(-60,0,0,1);
    glScalef(30,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1.0,0.0,0.0);
    glPopMatrix();



}
function_U()
{
    //left line
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(5,30,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.0,1.0,0.0);
    glPopMatrix();

    //base
    glPushMatrix();
    glTranslatef(8,-15,0);
    glScalef(20,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.0,1.0,0.0);
    glPopMatrix();

    //right line
    glPushMatrix();
    glTranslatef(15,0,0);
    glScalef(5,30,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.0,1.0,0.0);
    glPopMatrix();


}

void function_E()
{
    //base of line E
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(5,30,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    // line 1
    glPushMatrix();
    glTranslatef(10,10,0);
    glScalef(20,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    // line 2
    glPushMatrix();
    glTranslatef(10,0,0);
    glScalef(20,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    // line 3
    glPushMatrix();
    glTranslatef(10,-10,0);
    glScalef(20,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();


}
void function_T()
{
    // horizontal line
    glPushMatrix();
    glTranslatef(10,10,0);
    glScalef(25,5,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.0,0.0,1.0);
    glPopMatrix();

    // Vertical line
    glPushMatrix();
    glTranslatef(10,0,0);
    glScalef(5,25,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.0,0.0,1.0);
    glPopMatrix();


}

void display_setting()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    // xmin, xmax, ymin, ymax, near, far
    glFrustum(-5,5,-5,5, 4, 100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    // eye, look, head
    gluLookAt(0,10,40, 0,0,0, 0,1,0);

    glViewport(0, 0, windowHeight, windowWidth);
    glRotatef(theta,axis_x,axis_y,0);
    glTranslatef(0,0,Tzval);
}
void display(void)
{
    display_setting();

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    //axes();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35,0,0);
    glScalef(0.5,0.5,0.5);
    function_K();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0,0);
    glScalef(0.5,0.5,0.5);
    function_U();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,0,0);
    glScalef(0.5,0.5,0.5);
    function_E();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,0,0);
    glScalef(0.5,0.5,0.5);
    function_T();
    glPopMatrix();





    glFlush();
    glutSwapBuffers();

}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case 'l': // left
        theta++;
        axis_y=1;
        axis_x=0;
        break;
    case 'r': // right
        theta--;
        axis_y=1;
        axis_x=0;
        break;
    case 'd': // down
        theta++;
        axis_x=1;
        axis_y=0;
        break;
    case 'u': // up
        theta--;
        axis_x=1;
        axis_y=0;
    case '+': // zoom in
        Tzval+=0.2;
        break;
    case '-': // zoom out
        Tzval-=0.2;
        break;
    }

    glutPostRedisplay();
}


int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(windowHeight,windowWidth);
    glutCreateWindow("KUET: 1607048");
    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"-- KUET ---"<<endl;
    cout<<"-- Faisal Ahmed ----------"<<endl;
    cout<<"-- Roll: 1607048 ---------"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Press : u -> Rotate Up"<<endl;
    cout<<"Press : d -> Rotate Down"<<endl;
    cout<<"Press : l -> Rotate left"<<endl;
    cout<<"Press : r -> Rotate Right"<<endl;
    cout<<"Press : r -> Rotate Right"<<endl;
    cout<<"Press : + -> Zoom In"<<endl;
    cout<<"Press : - -> Zoom Out"<<endl;


    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
}
