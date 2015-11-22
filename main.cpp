#include <iostream>
#include <getopt.h>
#include <unistd.h>
#include "areaCells.h"

using namespace std;

#define FAULT 1 //exit code, no success
#define SUCCESS 0 //exit code on success
#define BLANK -1 //argument is blank

void printHelp()
{
    cout << "<<HELP TODO>>" << endl;
    return;
}

int main(int argc, char *argv[])
{
    int c; //variable for iteration trought comand line parameters, hold last parameter
    char *cvalue = NULL; //variable for value of specific argument (for -a 100, it is 100)

    int infectionTime = BLANK;
    int size = BLANK;
    int imunityTime = BLANK;
    int time = BLANK;

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
                time = atoi(optarg);
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
    if(infectionTime <= BLANK || imunityTime <= BLANK || time <= BLANK || size <= BLANK) //check if setings from parameters are not blank
    {
        cerr << "Invalid arguments! Type -h for help!" << endl;
        return FAULT;
    }

    //TODO
    cout << "M:" << imunityTime << " N:" << infectionTime << " T:" << time << endl;

    areaCells allCells(size, infectionTime, imunityTime);

    for(int i = 0; i < time; i++){
        allCells.updateMatrices();
    }

    //return SUCCESS;
    exit(SUCCESS);
}