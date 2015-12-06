/*
 * IMS Project - Application of celular automata in biology
 * Authors: Filip Gulan and Marek Marusic
 * E-mails: xgulan00@stud.fit.vutbr.cz and xmarus05@stud.fit.vutbr.cz
 */

#ifndef IMS_PROJEKT_CELLS_H
#define IMS_PROJEKT_CELLS_H

#include "cell.h"
#include <vector>

#define NOEXIST 0
#define EMPTY 0
#define STONE -1
#define NOPOPULATION 0
#define NEWPLANT 1

using namespace std;

class areaCells {
public:
    areaCells(int, int, int, int, int, int, int);
    void fillMatrix();
    void fillWithPlants();
    void updateMatrices();
    void evolve(int, int);
    void fillRock();
    int getNeighborsState(int i, int j);
    void showInCmd(void);
    void endShowCmd(void);
    //~areaCells(void);       //Destruktor

    int width;
    int deathTime;
    int vegetationTime;
    int extiction;
    int seedRain;
    int intenseExct;
    int currentTime;
    int Time;
    double populationPercent;
    std::vector<cell> matrixPresent;
    std::vector<cell> matrixFuture;
    std::vector<double> ocuppiedPercent;
};


#endif //IMS_PROJEKT_CELLS_H
