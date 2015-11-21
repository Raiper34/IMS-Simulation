//
// Created by marek on 11/21/15.
//

#ifndef IMS_PROJEKT_CELLS_H
#define IMS_PROJEKT_CELLS_H

#include "cell.h"
#include <vector>

using namespace std;

class areaCells {
public:
    areaCells(int size);        //Konstruktor
    ~areaCells(void);       //Destruktor

    int width;
    int time;
    std::vector<cell> matrixPresent;
    std::vector<cell> matrixFuture;
};


#endif //IMS_PROJEKT_CELLS_H
