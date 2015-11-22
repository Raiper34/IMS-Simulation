#include <iostream>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <GL/gl.h>
#include <GL/glu.h>

#include "areaCells.h"

using namespace std;

#define FAULT 1 //exit code, no success
#define SUCCESS 0 //exit code on success
#define BLANK -1 //argument is blank

//Global variables, needed becouse of display function
int infectionTime = BLANK;
int size = BLANK;
int imunityTime = BLANK;
int Time = BLANK;

void printHelp()
{
    cout << "<<HELP TODO>>" << endl;
    return;
}

void setup() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void display() {
    areaCells allCells(size, infectionTime, imunityTime);
    allCells.fillMatrix();


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat minSize = 60.0f/allCells.width;
    GLfloat istart = 0.0f;      //Y axis
    GLfloat jstart = 0.0f;     //X Yaxis
//    GLfloat iInc = -1 * minSize;
//    GLfloat jInc = minSize;


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 60, 60, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, 600, 600);


    for(int i = 0; i <= allCells.width; i++){
        for(int j = 0; j <= allCells.width; j++){
            glColor3f(0.0f, 0.0f, 1.0f);
            //glRectf(jstart,istart,jstart+jInc,istart+iInc);

            glColor3f(0.0f, 0.0f, 1.0f); // Let it be blue
            glBegin(GL_QUADS); // 2x2 pixels
            glVertex2f(0.0f+minSize*j, 0.0f+minSize*i);
            glVertex2f(0.0f+minSize*(j+1), 0.0f+minSize*i);
            glVertex2f(0.0f+minSize*(j+1), 0.0f+minSize*(i+1));
            glVertex2f(0.0f+minSize*j, 0.0f+minSize*(i+1));
            glEnd();


            glColor3f(0.0f, 0.0f, 0.0f); // Let it be yellow.
            glBegin(GL_LINE_STRIP);
            glVertex2f(0.0f+minSize*j, 0.0f+minSize*i);
            glVertex2f(0.0f+minSize*(j+1), 0.0f+minSize*i);
            glVertex2f(0.0f+minSize*(j+1), 0.0f+minSize*(i+1));
            glVertex2f(0.0f+minSize*j, 0.0f+minSize*(i+1));
            glEnd();
        }
    }




    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    int c; //variable for iteration trought comand line parameters, hold last parameter
    char *cvalue = NULL; //variable for value of specific argument (for -a 100, it is 100)

    while((c = getopt(argc, argv, "s:n:m:t:h")) != -1) //iterate trought all parameters of comand line
    {
        switch (c)
        {
            case 'n': //infection argument
                infectionTime = atoi(optarg);
                break;
            case 's': //infection argument
                size = atoi(optarg);
                break;
            case 'm': //imunity argument
                imunityTime = atoi(optarg);
                break;
            case 't': //time argument
                Time = atoi(optarg);
                break;
            case 'h': //time argument
                printHelp();
                return SUCCESS;
            case '?': //somethink unkown as value
                cerr << "Unkown option -" << (char) optopt << "! Type -h for help!" << endl;
                return FAULT;
            default: //somethink unkown
                return FAULT;
        }
    }
    if(infectionTime <= BLANK || imunityTime <= BLANK || Time <= BLANK || size <= BLANK) //check if setings from parameters are not blank
    {
        cerr << "Invalid arguments! Type -h for help!" << endl;
        return FAULT;
    }

    //TODO
    cout << "M:" << imunityTime << " N:" << infectionTime << " T:" << time << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Hello World");

    setup();
    glutDisplayFunc(display);

    glutMainLoop();

    exit(SUCCESS);
}