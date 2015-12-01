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
    areaCells(int, int, int, int, int);
    void fillMatrix(int cmdLine);
    void updateMatrices(int);
    void evolve(int, int);
    int getNeighborsState(int i, int j);


    void showInCmd(void);
    void endShowCmd(void);

    ~areaCells(void);       //Destruktor

    int width;
    int deathTime;
    int vegetationTime;
    int extiction;
    int seedRain;
    double populationPercent;
    std::vector<cell> matrixPresent;
    std::vector<cell> matrixFuture;
};


#endif //IMS_PROJEKT_CELLS_H
