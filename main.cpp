#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
#include <stdlib.h>
//#include <irrklang/irrKlang.h>
#define rad (3.1416/180)
#define EN_SIZE 20

using namespace std;
//using namespace irrklang;

//ISoundEngine *SoundEngine = createIrrKlangDevice();


float zoom=4;
int occurence[5000][5000];
float tX=0,tY=0,tZ=-8,rX=0,rY=0,rZ=4;
float tZ1=-20,tZ2=-40,tZ3=-60,tZ4=-80,tZ5=-100,tZ6=-120;
float rotX=0,rotY=0,rotZ=0;
float cosX=0,cosY=1,cosZ=0;
float angle=0;
float xEye=0.0f,yEye=5.0f,zEye=30.0f;
float cenX=0,cenY=0,cenZ=0,roll=0;
float radius=0;
float theta=0,slope=0;
float speed = 0.3;
float angleBackFrac = 0.2;
bool saheedMinarVisible = false;
float r[] = {0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0,1,0};
float g[] = {0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2,0,0.2};
float b[] = {0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0,0,0};
int TIME=0;
bool START = false;
float torusPosX[7] = {1,-2,3,-4,-2,0,2};
float torusPosY[7] = {2,3,10,6,7,4,1};
bool SELECT = false;
int plane_type = 0;
bool INS = false;
bool rot = false;


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawMonument(){
    glColor3d(0.4,0.2,0.2);
	glPushMatrix();
        glTranslated(0,1.55,0);
        glScaled(2,0.05,1.5);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.4,0.2,0.2);
	glPushMatrix();
        glTranslated(0,1.6,0);
        glScaled(1.9,0.05,1.4);
        glutSolidCube(1);
    glPopMatrix();

    //glColor3d(0.4,0.2,0.2);
    //glColor3d(1,0.8,0.7);
    glColor3d(0.4,0.2,0.2);
	glPushMatrix();
        glTranslated(0,1.65,0);
        glScaled(1.8,0.05,1.3);
        glutSolidCube(1);
    glPopMatrix();

    // white base
    glColor3d(1,1,1);
	glPushMatrix();
        glTranslated(0,1.68,-0.4);
        glScaled(0.5,0.02,0.08);
        glutSolidCube(2);
    glPopMatrix();

    // Pillar
	glPushMatrix();
        glTranslated(0,1.99,-0.4);
        glScaled(0.06,0.7,0.04);
        glutSolidCube(2);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.07,1.99,-0.4);
        glScaled(0.003,0.7,0.003);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.11,1.99,-0.4);
        glScaled(0.003,0.7,0.003);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.15,1.99,-0.4);
        glScaled(0.003,0.7,0.003);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.22,0,0);
        glPushMatrix();
            glTranslated(0.07,1.99,-0.4);
            glScaled(0.003,0.7,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.11,1.99,-0.4);
            glScaled(0.003,0.7,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.15,1.99,-0.4);
            glScaled(0.003,0.7,0.003);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    //Horizontal rod
    glPushMatrix();
        glTranslated(2.2,0,-0.1);
        glScaled(4.2,1,1);
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.528,1.85,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.02,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.18,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();
        glColor3d(1,1,1);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-0.22,1.99,-0.4);
        glScaled(0.06,0.7,0.04);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.22,1.99,-0.4);
        glScaled(0.06,0.7,0.04);
        glutSolidCube(1);
    glPopMatrix();

    // Shade

    glPushMatrix();
        glTranslated(0,0.743,-1.424);
        glRotated(45,1,0,0);
        glPushMatrix();
            glTranslated(0,1.99,-0.4);
            glScaled(0.06,0.3,0.04);
            glutSolidCube(5);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.22,1.99,-0.4);
            glScaled(0.06,0.3,0.04);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.22,1.99,-0.4);
            glScaled(0.06,0.3,0.04);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0,2.15,-0.4);
            glScaled(0.5,0.04,0.04);
            glutSolidCube(1);
        glPopMatrix();

        glColor3d(0,0,0);

        glPushMatrix();
            glTranslated(0.07,1.99,-0.4);
            glScaled(0.003,0.277,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.11,1.99,-0.4);
            glScaled(0.003,0.277,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.15,1.99,-0.4);
            glScaled(0.003,0.277,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glColor3d(0,0,0);
        glPushMatrix();
        glTranslated(-0.22,0,0);
            glPushMatrix();
                glTranslated(0.07,1.99,-0.4);
                glScaled(0.003,0.277,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.277,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.15,1.99,-0.4);
                glScaled(0.003,0.277,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.2,0,-0.1);
            glScaled(4.2,1,1);
                glColor3d(0,0,0);
                glPushMatrix();
                    glTranslated(-0.528,1.85,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(-0.528,2,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(-0.528,2.15,-0.3);
                    glScaled(0.1,0.003,0.003);
                    glutSolidCube(1);
                glPopMatrix();
                glColor3d(1,1,1);
        glPopMatrix();

    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0.1,0,-0.4);
        glRotated(45,0,1,0);

        glPushMatrix();
            glTranslated(-0.605,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.45,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.258,-0.3);
            glScaled(0.199,0.04,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,1.68,-0.3);
            glScaled(0.199,0.02,0.06);
            glutSolidCube(1);
        glPopMatrix();

        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.64,-0.05,0.1);
            glScaled(1,1.02,1);
            glPushMatrix();
                glTranslated(0.078,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.145,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();


        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.528,1.85,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.15,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();
        glColor3d(1,1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.65,0,0.3);
        glRotated(-45,0,1,0);

        glPushMatrix();
            glTranslated(-0.605,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.45,1.94,-0.3);
            glScaled(0.045,0.65,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.258,-0.3);
            glScaled(0.199,0.04,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,1.68,-0.3);
            glScaled(0.199,0.02,0.06);
            glutSolidCube(1);
        glPopMatrix();

        glColor3d(0,0,0);
        glPushMatrix();
        glTranslated(-0.64,-0.05,0.1);
            glScaled(1,1.02,1);
            glPushMatrix();
                glTranslated(0.078,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.145,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();
        glColor3d(1,1,1);

        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.528,1.85,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.15,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();
        glColor3d(1,1,1);

    glPopMatrix();

    glPushMatrix();
        glTranslated(0.06,0,0.14);
        glPushMatrix();
            glTranslated(-0.2,0,-0.31);
            glRotated(45,0,1,0);
            glPushMatrix();
                glTranslated(-0.605,1.88,-0.3);
                glScaled(0.045,0.4,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.45,1.88,-0.3);
                glScaled(0.045,0.4,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,2.08,-0.3);
                glScaled(0.2,0.04,0.03);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(-0.528,1.68,-0.3);
                glScaled(0.199,0.02,0.06);
                glutSolidCube(1);
            glPopMatrix();

        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.641,0.43,0.1);
            glScaled(1,0.73,1);
                glPushMatrix();
                    glTranslated(0.078,1.99,-0.4);
                    glScaled(0.003,0.56,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(0.11,1.99,-0.4);
                    glScaled(0.003,0.56,0.003);
                    glutSolidCube(1);
                glPopMatrix();

                glPushMatrix();
                    glTranslated(0.145,1.99,-0.4);
                    glScaled(0.003,0.56,0.003);
                    glutSolidCube(1);
                glPopMatrix();
        glPopMatrix();

        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.528,1.8,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,1.96,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();
        glColor3d(1,1,1);

    glPopMatrix();

    glPushMatrix();
        glTranslated(0.83,0,0.39);
        glRotated(-45,0,1,0);
        glPushMatrix();
            glTranslated(-0.605,1.88,-0.3);
            glScaled(0.045,0.4,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.45,1.88,-0.3);
            glScaled(0.045,0.4,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,2.1,-0.3);
            glScaled(0.199,0.04,0.03);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,1.68,-0.3);
            glScaled(0.199,0.02,0.06);
            glutSolidCube(1);
        glPopMatrix();

        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.528,1.8,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.528,1.96,-0.3);
            glScaled(0.1,0.003,0.003);
            glutSolidCube(1);
        glPopMatrix();
        glColor3d(1,1,1);

        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(-0.641,0.43,0.1);
            glScaled(1,0.73,1);
            glPushMatrix();
                glTranslated(0.078,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.11,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.145,1.99,-0.4);
                glScaled(0.003,0.56,0.003);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();
        glColor3d(1,1,1);
        glPopMatrix();

    glPopMatrix();

    // Pillar background
    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(0,2.1,-0.44);
        glScaled(0.35,0.35,0.01);
        glutSolidSphere(5,50,50);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(-0.18,1.9,-0.45);
        glScaled(0.01,0.5,0.01);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.18,1.9,-0.45);
        glScaled(0.01,0.5,0.01);
        glutSolidCube(1);
    glPopMatrix();
}

void fan(){
    glColor3d(0.5,1,0);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(1,1,0.7);
        glutSolidSphere(0.8,30,30);
    glPopMatrix();

    glColor3d(0.5,1,0);
    glPushMatrix();
        glTranslated(0,0,0);
        glRotated(5,0,1,0);
        glScaled(0.5,2.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(0.5,1,0);
    glPushMatrix();
        glTranslated(0,0,0);
        glRotated(-5,0,1,0);
        glRotated(90,0,0,1);
        glScaled(0.5,2.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();
}

void plane(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    // Fuselage
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(3,0.4,0.5);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(1.7,0.1,0);
        glScaled(1.5,0.7,0.8);
        glRotated(40,0,1,0);
        glutSolidSphere(0.45,30,30);
    glPopMatrix();

    //Right wing
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,1.2);
        glRotated(-50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(25,0,1,0);
        glutSolidCube(1);
    glPopMatrix();

    // Turbine R2
    glColor3d(0,0,0.8);
    glPushMatrix();
        glTranslated(-0.3,-0.15,1.5);
        glRotated(90,0,1,0);
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    // Turbine R1
    glColor3d(0,0,0.8);
    glPushMatrix();
        glTranslated(0.4,-0.15,0.9);
        glRotated(90,0,1,0);
/*        // FAN
        glPushMatrix();
            glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();
*/
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    // Left wing
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,-1.2);
        glRotated(50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(-25,0,1,0);
        glutSolidCube(1);
    glPopMatrix();

    // Turbine L2
    glColor3d(0,0,0.9);
    glPushMatrix();
        glTranslated(-0.3,-0.15,-1.5);
        glRotated(90,0,1,0);
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    // Turbine L1
    glColor3d(0,0,0.9);
    glPushMatrix();
        glTranslated(0.2,-0.15,-0.9);
        glRotated(90,0,1,0);
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();
/*
    // Horizontal Stabilizer
    glPushMatrix();
        glTranslated(-2.8,0,0);
        glScaled(0.8,0.5,0.3);

        // Right
        glColor3d(0.8,1,0);
        glPushMatrix();
            glTranslated(0.4,0,1.5);
            glRotated(-30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();

        // Left
        glColor3d(0.8,1,0);
        glPushMatrix();
            glTranslated(0.4,0,-1.5);
            glRotated(30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(-10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
*/
    // Vertical Stabilizer
    glColor3d(0,0,0.9);
    glPushMatrix();
        glTranslated(-2.7,0.5,0);
        glRotated(45,0,0,1);
        glScaled(0.8,2,0.1);
        glRotated(-20,0,0,1);
        glutSolidCube(0.5);
    glPopMatrix();
}

void jet(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    //Right wing
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,1);
        glRotated(-50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(25,0,1,0);
        glutSolidCube(0.9);
    glPopMatrix();

    // Left wing
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,-1);
        glRotated(50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(-25,0,1,0);
        glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,0,0);
        glRotated(50,0,1,0);
    glPopMatrix();

    // Horizontal Stabilizer
    glPushMatrix();
        glTranslated(-2.8,0,0);
        glScaled(0.8,0.5,0.3);

        // Right
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(4,0,1.3);
            glRotated(-30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();

        // Left
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(4,0,-1.3);
            glRotated(30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(-10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    // Horizontal Stabilizer
    glPushMatrix();
        glTranslated(-2.8,0,0);
        glScaled(0.8,0.5,0.3);

        // Right
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(3,0,1.3);
            glRotated(30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();

        // Left
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(3,0,-1.3);
            glRotated(-30,0,1,0);
            glScaled(0.7,0.1,3);
            glRotated(-10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    // Vertical Stabilizer
    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(-1,0.5,0.3);
        glRotated(25,15,0,1);
        glScaled(0.8,2,0.1);
        glRotated(-20,0,0,1);
        glutSolidCube(0.5);
    glPopMatrix();

    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(-1,0.5,-0.3);
        glRotated(25,-15,0,1);
        glScaled(0.8,2,0.1);
        glRotated(-20,0,0,1);
        glutSolidCube(0.5);
    glPopMatrix();
}

void singleTolaHouse(int R,int G,int B){
    glColor3d(r[R%11],g[G%11],b[B%11]);
    glPushMatrix();
        glTranslated(0,0,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(-0.2,0,0);
        glScaled(0.3,0.3,1.001);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,-0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

}

void house(int n,int R,int G){
    for(int i=0;i<n;i++){
        glPushMatrix();
            glTranslated(0,0.8+i,0);
            singleTolaHouse(G,R,i);
        glPopMatrix();
    }
}

void soheedMinarEnv(){
    /// Ground
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(EN_SIZE*2,0.3,EN_SIZE*2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-8,-2.7,-5);
        glRotated(65,0,1,0);
        //glRotated(15,0,1,0);
        glScaled(2,2,2);
        drawMonument();
    glPopMatrix();

    glPushMatrix();
        glTranslated(8,-2.7,-5);
        glRotated(-65,0,1,0);
        //glRotated(15,0,1,0);
        glScaled(2,2,2);
        drawMonument();
    glPopMatrix();
}

void environment(int n){

    // Road
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(EN_SIZE*2,0.3,EN_SIZE*2);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.89,0.34,0.13);
    glPushMatrix();
        glTranslated(torusPosX[n],torusPosY[n],0);
        glScaled(0.3,0.3,0.3);
        glutSolidTorus(0.7,3,30,30);
    glPopMatrix();

        for(int i=-(EN_SIZE/2)+1;i<(EN_SIZE/2);i+=2){
            for(int j=-(EN_SIZE/2)+1;j<(EN_SIZE/2);j+=2){
                if(occurence[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]!=0){
                    glPushMatrix();
                        glTranslated(i,0,j);
                        house(occurence[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
                    glPopMatrix();
                }else if(i>=-5&&i<=5){}
                else{
                    occurence[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]=(rand()%5)+1;
                    glPushMatrix();
                        glTranslated(i,0,j);
                        house(occurence[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1],i,j);
                    glPopMatrix();
                }
            }
        }

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(1,0.6,4);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(6,10,0);
        glRotated(90,0,1,0);
        glScaled(0.2,0.2,0.9);
        glutSolidTorus(2,0.5,50,50);
    glPopMatrix();

    glColor3d(0.7,0.7,0.7);
    glPushMatrix();
        glTranslated(-6,10,3);
        glRotated(90,0,1,0);
        glScaled(0.2,0.2,0.9);
        glutSolidTorus(2,0.5,50,50);
    glPopMatrix();
}

void draw(){
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    TIME = t;

    // Plane 1
    if(plane_type == 1){
        if(rotX>11)rotX=11;
        if(rotX<-11)rotX=-11;
        if(rotZ>10)rotZ=10;
        if(rotZ<-15)rotZ=-15;

        glPushMatrix();
            glTranslated(0,1,0);
            glRotated(90,0,1,0);
            glRotated(5,0,0,1);
            glRotated(rotX,1,0,0);
            glRotated(rotY,0,1,0);
            glRotated(rotZ, 0,0,1);

            glScaled(0.4,0.4,0.4);
            plane();
        glPopMatrix();
    }else{                  // Plane 2
        if(rotX>11)rotX=11;
        if(rotX<-11)rotX=-11;
        if(rotZ>10)rotZ=10;
        if(rotZ<-15)rotZ=-15;

        glPushMatrix();
            glTranslated(0,1,0);
            glRotated(90,0,1,0);
            glRotated(5,0,0,1);
            glRotated(rotX,1,0,0);
            glRotated(rotY,0,1,0);
            glRotated(rotZ,0,0,1);

            glScaled(0.4,0.4,0.4);
            jet();
        glPopMatrix();
    }

    ///Environment
    if(tX>=4.1)tX=4.1;
    if(tX<=-4.1)tX=-4.1;
    if(tY>0.1)tY= 0.1;
    if(tY<-15)tY= -15;

    glPushMatrix();
        glTranslated(tX,tY,tZ);
        environment(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ1);
        soheedMinarEnv();
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ2);
        environment(3);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ3);
        environment(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ4);
        environment(5);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ5);
        environment(4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ6);
        environment(2);
    glPopMatrix();

    tZ+=speed;
    tZ1+=speed;
    tZ2+=speed;
    tZ3+=speed;
    tZ4+=speed;
    tZ5+=speed;
    tZ6+=speed;

    if(tZ>=20)tZ=-110;
    if(tZ1>=20)tZ1=-110;
    if(tZ2>=20)tZ2=-110;
    if(tZ3>=20)tZ3=-110;
    if(tZ4>=20)tZ4=-110;
    if(tZ5>=20)tZ5=-110;
    if(tZ6>=20)tZ6=-110;

    if(rotX>0)rotX-=angleBackFrac;
    if(rotX<0)rotX+=angleBackFrac;
    if(rotY>0)rotY-=angleBackFrac;
    if(rotY<0)rotY+=angleBackFrac;
    if(rotZ>0)rotZ-=angleBackFrac;
    if(rotZ<0)rotZ+=angleBackFrac;

    speed += 0.000002;
    if(speed>=0.6){
        speed=0.6;
    }
}


void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x,y+8,z);

	for (c=str; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawStrokeText(char* str,int x,int y,int z)
{
	  char *c;
	  glColor3d(0,0,0);
	  glPushMatrix();
	    glTranslatef(x, y+8,z);
	    glScalef(0.002f,0.002f,z);

	    for (c=str; *c != '\0'; c++)
	    {
    	    glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	    }
	  glPopMatrix();
}

void drawStrokeText2(char* str,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
        glTranslatef(x, y+8,z);
        glScalef(0.005f,0.005f,z);

        for (c=str; *c != '\0'; c++)
        {
            glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
        }
	  glPopMatrix();
}
void drawStrokeChar(char c,float x,float y,float z)
{
	  glPushMatrix();
          glTranslatef(x, y+8,z);
          glScalef(0.002f,0.002f,z);
          glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
	  glPopMatrix();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
    double aa=a;

    if(!rot){
        a=0;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(	0.0, 4.5, 10.0,
                0, 4, 0,
                0, 1.0f, 0.0f);

    if(START){

        glPushMatrix();
            glTranslated(0,0,0);
            glScaled(zoom,zoom,zoom);
            glRotated(a,0,1,0);
            draw();
        glPopMatrix();

        drawStrokeText("UP: W, DOWN: S, LEFT: A, RIGHT: D, MAIN MENU: M",-8,0.9,0);
        drawStrokeText("TIME : ",3,0,0);
        int mod,number=0;
        while(TIME){
            mod=TIME%10;
            number=number*10+mod;
            TIME/=10;
        }
        float tmp=0;
        while(number){
            mod=number%10;
            drawStrokeChar(mod+48,4+tmp,0,0);
            number/=10;
            tmp+=0.2;
        }
    }else if(SELECT){
        drawStrokeText("Select Plane",-1,0,0);
        drawStrokeText("Press 1",-5,-2,0);
        drawStrokeText("Press 2",2,-2,0);

        glPushMatrix();
            glTranslated(-4,3,0);
            glScaled(1,1,1);
            glRotated(aa,0,1,0);
            plane();
        glPopMatrix();

        glPushMatrix();
            glTranslated(4,3,0);
            glScaled(1,1,1);
            glRotated(aa,0,1,0);
            jet();
        glPopMatrix();

/*
        glPushMatrix();
            glTranslated(0,3,0);
            glRotated(aa,0,1,0);
            glScaled(1.5,1.5,1.5);
            plane();
        glPopMatrix();
*/
    }else if(INS){

        drawStrokeText("g : Start game",-4,0,0);
        drawStrokeText("w : Up",-4,-1,0);
        drawStrokeText("s : Down",4,-1,0);
        drawStrokeText("a : Left",-4,-2,0);
        drawStrokeText("d : Right",4,-2,0);
        drawStrokeText("m : Home",-4,-3,0);
        drawStrokeText("q : Quit",4,-3,0);
        drawStrokeText("r : Rotating View Camera",4,-4,0);
        drawStrokeText("t : Back View camera",-4,-4,0);
        drawStrokeText("z : Zoom in",-4,-5,0);
        drawStrokeText("x : Zoom out",4,-5,0);
    }else{

        drawStrokeText("Press g to Start",-2,-1,0);
        drawStrokeText("Press k to change plane",-2,-3,0);
        drawStrokeText("Press i for instructions",-2,-5,0);
        drawStrokeText2("Plane Ride",-2,0,0);
    }

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    float frac = 0.3;
    float rotFrac = 2;
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'r':
            rot=true;
            break;
        case 't':
            rot=false;
            break;
        case 'z':
            zoom+=0.05;
            break;
        case 'x':
            zoom-=0.05;
        case 'w':
            tY-=frac;
            rotZ+=rotFrac;
            break;
        case 's':
            tY+=frac;
            rotZ-=rotFrac;
            break;
        case 'a':
            tX+=frac;
            rotX-=rotFrac*3;
            rotY+=rotFrac/2;
            break;
        case 'd':
            tX-=frac;
            rotX+=rotFrac*3;
            rotY-=rotFrac/2;
            break;
        case 'g':
            START = true;
            SELECT = false;
            INS = false;
            break;
        case 'm':
            START = false;
            SELECT = false;
            INS = false;
            break;
        case 'k':
            START = false;
            SELECT = true;
            break;
        case '1':
            plane_type = 1;
            START = true;
            break;
        case '2':
            plane_type = 2;
            START = true;
            break;
        case 'i':
            INS = true;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    //SoundEngine -> play2D("5 Seconds of Summer - Easier (Official Video).mp3", GL_TRUE);

    glClearColor(0.53,0.8,0.95,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
