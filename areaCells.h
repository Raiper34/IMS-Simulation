//
// Created by marek on 11/21/15.
//

#ifndef IMS_PROJEKT_CELLS_H
#define IMS_PROJEKT_CELLS_H

#include "cell.h"
#include <vector>

#define NOEXIST 0

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

    ~areaCells(void);       //Destruktor

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
