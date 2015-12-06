/*
 * IMS Project - Application of celular automata in biology
 * Authors: Filip Gulan and Marek Marusic
 * E-mails: xgulan00@stud.fit.vutbr.cz and xmarus05@stud.fit.vutbr.cz
 */

#include <iostream>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <GL/gl.h>
#include <GL/glu.h>
#include <fstream>
#include <iomanip>

#include "areaCells.h"

using namespace std;

#define FAULT 1 //exit code, no success
#define SUCCESS 0 //exit code on success
#define BLANK -1 //argument is blank
#define DEFINED 1 //argument is defined
#define UNDEFINED -1
#define EMPTY 0
#define STONE -1

//Global variables, needed becouse of OPENGL display function
int width = BLANK;
int vegetationTime = BLANK;
int deathTime = BLANK;
int seedRain = 0;
int extiction = 0;
int intenseExct = 0;
string fileOut = "";
int Time = BLANK;
int graphic = UNDEFINED;
int cmdLine = UNDEFINED;
int speed = BLANK;
int avg = UNDEFINED;
int mode = UNDEFINED;
int rock = UNDEFINED;

/*
 * Function, that print results of simulation
 */
void printOutput(areaCells allCells){
    //Open file or cout
    ofstream f;

    if(fileOut != "") //file to write is specified
        f.open(fileOut.c_str(), std::ios::out);

    std::ostream & outFile = (f.is_open() ? f : std::cout);

    //print to ostream
    if(avg == DEFINED) //get avarange percent of plants occupied lattice
    {
        double average = 0.0;
        for(int i = 0; i < allCells.ocuppiedPercent.size(); i++)
        {
            average += allCells.ocuppiedPercent[i];
        }
        average = average/double(allCells.ocuppiedPercent.size());
        outFile << std::setprecision(5) << average << endl;
    }
    else //we want normal values for line graph
    {
        outFile << "Čas [rok]" << "," << "Obsadená časť [%]" << endl;
        for(int i = 0; i < allCells.ocuppiedPercent.size(); i++)
        {
            outFile << i+1 << "," << std::setprecision(5) << allCells.ocuppiedPercent[i] << endl;
        }
    }

    //Close file
    if (f.is_open())
    {
        f.close();
    }
}

/*
 * Function to print help to stdin
 */
void printHelp()
{
    cout << "-------------------------------------------------------------------" << endl;
    cout << "IMS Project - Application of celular automata in biology" << endl;
    cout << "Authors: Filip Gulan and Marek Marusic" << endl;
    cout << "E-mails: xgulan00@stud.fit.vutbr.cz and xmarus05@stud.fit.vutbr.cz" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Parameters:" << endl;
    cout << "   Required:" << endl;
    cout << "       -w X: width of matrix" << endl;
    cout << "       -t X: time of simulation in years" << endl;
    cout << "       -d X: death time of plant" << endl;
    cout << "   Optional:" << endl;
    cout << "       -v X: vegetation time of plant" << endl;
    cout << "       -r X: probability of seed rain in percent" << endl;
    cout << "       -e X: exctition probability in percent" << endl;
    cout << "       -x X: intensity of one time exctition in percent" << endl;
    cout << "       -f X: file to write simulation results to X file" << endl;
    cout << "       -s X: speed of simulation, 1 very slow, 1000 very fast" << endl;
    cout << "       -m: second mode, that fills matrix with plants" << endl;
    cout << "       -a: get avarange percent of plants in matrix during simulation" << endl;
    cout << "       -k: stone mode simulation" << endl;
    cout << "       -g: graphical OPENGL visualisation" << endl;
    cout << "       -c: command line visualisation" << endl;
    cout << "       -h: print this help" << endl;
    return;
}

/*
 * Function to set up OPENGL
 */
void setup() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

/*
 * Function to display OPENGL window
 */
void display()
{
    areaCells allCells(width, deathTime, vegetationTime, seedRain, extiction, Time, intenseExct);
    allCells.fillMatrix();
    //srand(time(NULL));
    if(mode == DEFINED) //second mode, matrix is prefilled with plants
    {
        allCells.fillWithPlants();
    }
    if(rock == DEFINED) //second mode, matrix is prefilled with plants
    {
        allCells.fillRock();
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int t = 0; t < Time; t++) //simulate for t years
    {
        //DISPLAY THE MATRIX
        GLfloat minSize = 60.0f/allCells.width;
        GLfloat greenIncrement = 0.5f/deathTime;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, 60, 60, 0.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glViewport(0, 0, 600, 600);

        for(int i = 0; i <= allCells.width; i++) //for row in matrix
        {
            for(int j = 0; j <= allCells.width; j++) //for col in matrix
            {
                if(allCells.matrixPresent[i + j * allCells.width].state == EMPTY)
                    glColor3f(0.32157f, 0.0941f, 0.0f);// Let it be brown
                else if(allCells.matrixPresent[i + j * allCells.width].state == STONE)
                    glColor3f(0.0f, 0.301f, 0.301f);// Let it be dark blue
                else
                    glColor3f(0.0f, 0.470f+(greenIncrement * allCells.matrixPresent[i + j * allCells.width].state), 0.0f);// Let it be green

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
        usleep(speed);
        allCells.updateMatrices();
    }
    printOutput(allCells);
}

/*
 * Main function
 */
int main(int argc, char *argv[])
{
    int c; //variable for iteration trought comand line parameters, hold last parameter
    char *cvalue = NULL; //variable for value of specific argument (for -a 100, it is 100)

    while((c = getopt(argc, argv, "kamf:v:d:s:e:x:r:w:t:hgc")) != -1) //iterate trought all parameters of comand line
    {
        switch(c)
        {
            case 'a':
                avg = DEFINED;
                break;
            case 'f': //file to write results
                fileOut = optarg;
                break;
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
            case 'm': //second mode
                mode = DEFINED;
                break;
            case 'x': //intenseSingleExtiction
                intenseExct = atoi(optarg);
                break;
            case 'w': //exictionTimeProhability
                width = atoi(optarg);
                break;
            case 't': //time argument
                Time = atoi(optarg);
                break;
            case 'k': //time argument
                rock = DEFINED;
                break;
            case 'g': //opengl graphical visualisation
                graphic = DEFINED;
                break;
            case 'c': //comandline text visualisation
                cmdLine = DEFINED;
                break;
            case 'h': //help
                printHelp();
                return SUCCESS;
            case '?': //somethink unkown as value
                cerr << "Unkown option -" << (char) optopt << "! Type -h for help!" << endl;
                return FAULT;
            default: //somethink unkown
                return FAULT;
        }
    }

    if(deathTime <= BLANK || Time <= BLANK || width <= BLANK) //check if setings from parameters are not blank
    {
        cerr << "Invalid arguments! Type -h for help!" << endl;
        return FAULT;
    }

    if(speed <= 0 ) //if speed is not specified with arguments
        speed = 1000000;
    else //speed of simulation is specified
        speed = 1000000/speed;

    srand(time(NULL));
    if(graphic == DEFINED) //start simulation in graphic mode using openGL
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
        areaCells allCells(width, deathTime, vegetationTime, seedRain, extiction, Time, intenseExct);
        allCells.fillMatrix();
        if(mode == DEFINED) //second mode, matrix is prefilled with plants
        {
            allCells.fillWithPlants();
        }
        if(rock == DEFINED) //mode with stone
        {
            allCells.fillRock();
        }
        for(int i = 0; i < Time; i++) //simulate from time 0 to specified time
        {
            if(cmdLine == DEFINED) //comandline visualisation
            {
                allCells.showInCmd();
                usleep(speed);
            }
            allCells.updateMatrices();
        }
        if(cmdLine == DEFINED) //comandline visualisation add new lines at the end
        {
            allCells.endShowCmd();
        }
        printOutput(allCells);
    }

    exit(SUCCESS);
}