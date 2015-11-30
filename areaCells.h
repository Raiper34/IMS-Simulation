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
    areaCells(int, int, int);        //Konstruktor
    void fillMatrix(int cmdLine);
    void updateMatrices(int);
    void evolve(int, int);
    double getPopSick(int, int);
    int getInf(int, int);
    void showInCmd(void);
    void endShowCmd(void);
    double highestValue(double, double, double, double);
    void countPopSick(int, int);
    ~areaCells(void);       //Destruktor

    int width;
    int infectionTime;
    int imunityTime;
    std::vector<cell> matrixPresent;
    std::vector<cell> matrixFuture;
};


#endif //IMS_PROJEKT_CELLS_H
