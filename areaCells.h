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
    void fillMatrix(void);
    void updateMatrices(void);
    void evolve(int, int);
    int getPopSick(int, int);
    void showInCmd(void);
    void endShowCmd(void);
    ~areaCells(void);       //Destruktor

    int width;
    int infectionTime;
    int imunityTime;
    std::vector<cell> matrixPresent;
    std::vector<cell> matrixFuture;
};


#endif //IMS_PROJEKT_CELLS_H
