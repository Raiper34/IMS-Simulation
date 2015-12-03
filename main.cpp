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
int width = BLANK;
int vegetationTime = BLANK;
int deathTime = BLANK;
int seedRain = 0;
int extiction = 0;
int Time = BLANK;
int graphic = BLANK;
int cmdLine = BLANK;
int speed = BLANK;

void printHelp()
{
    cout << "<<HELP TODO>>" << endl;
    return;
}

void setup() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void display()
{
    areaCells allCells(width, deathTime, vegetationTime, seedRain, extiction);
    allCells.fillMatrix();
    srand(time(NULL));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int t = 0; t < Time; t++)
    {
        //DISPLAY THE MATRIX
        GLfloat minSize = 60.0f/allCells.width;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, 60, 60, 0.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glViewport(0, 0, 600, 600);

        for(int i = 0; i <= allCells.width; i++){
            for(int j = 0; j <= allCells.width; j++){
                //if (allCells.matrixPresent[i + j * allCells.width].state == 2)
                    //glColor3f(1.0f, 0.0f, 0.0f);// Let it be red
                if(allCells.matrixPresent[i + j * allCells.width].state == 0)
                    glColor3f(0.0f, 1.0f, 0.0f);// Let it be green
                //else if(allCells.matrixPresent[i + j * allCells.width].state == 1)
                    //glColor3f(1.0f, 1.0f, 1.0f);// Let it be green
                else
                    glColor3f(0.0f, 0.0f, 1.0f);// Let it be blue

                glBegin(GL_QUADS); // 2x2 pixels
                glVertex2f(0.0f+minSize*j, 0.0f+minSize*i);
                glVertex2f(0.0f+minSize*(j+1), 0.0f+minSize*i);
                glVertex2f(0.0f+minSize*(j+1), 0.0f+minSize*(i+1));
                glVertex2f(0.0f+minSize*j, 0.0f+minSize*(i+1));
                glEnd();

                glEnd();

            }
        }
        glutSwapBuffers();
        cout << t << "," << allCells.populationPercent << endl;
        usleep(speed);
        allCells.updateMatrices();
    }
}


int main(int argc, char *argv[])
{
    int c; //variable for iteration trought comand line parameters, hold last parameter
    char *cvalue = NULL; //variable for value of specific argument (for -a 100, it is 100)

    while((c = getopt(argc, argv, "v:d:s:e:r:w:t:hgc")) != -1) //iterate trought all parameters of comand line
    {
        switch(c)
        {
            case 'v': //vegetation time
                vegetationTime = atoi(optarg);
                break;
            case 'd': //death time
                deathTime = atoi(optarg);
                break;
            case 'r': //seedRain prohability
                seedRain = atoi(optarg);
                break;
            case 's': //seedRain prohability
                speed = atoi(optarg);
                break;
            case 'e': //exictionTimeProhability
                extiction = atoi(optarg);
                break;
            case 'w': //exictionTimeProhability
                width = atoi(optarg);
                break;
            case 't': //time argument
                Time = atoi(optarg);
                break;
            case 'g': //time argument
                graphic = 1;
                break;
            case 'c': //time argument
                cmdLine = 1;
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

    if(vegetationTime <= BLANK || deathTime <= BLANK || Time <= BLANK || width <= BLANK) //check if setings from parameters are not blank
    {
        cerr << "Invalid arguments! Type -h for help!" << endl;
        return FAULT;
    }

    if(speed <= 0 ) //if speed is not specified with arguments
        speed = 1000000;
    else //speed of simulation is specified
        speed = 1000000/speed;

    if(graphic == 1) //start simulation in graphic mode using openGL
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
        glutInitWindowSize(600,600);
        glutCreateWindow("Celular automata");

        setup();
        glutDisplayFunc(display);

        glutMainLoop();
    }
    else //start simulation in comandline visualisation or without visualisation
    {
        areaCells allCells(width, deathTime, vegetationTime, seedRain, extiction);
        allCells.fillMatrix();
        for(int i = 0; i < Time; i++) //simulate from time 0 to specified time
        {
            if(cmdLine == 1) //comandline visualisation
            {
                allCells.showInCmd();
                usleep(speed);
            }
            allCells.updateMatrices();
        }
        if(cmdLine == 1) //comandline visualisation add new lines at the end
        {
            allCells.endShowCmd();
        }
    }

    exit(SUCCESS);
}