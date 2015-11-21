//
// Created by marek on 11/21/15.
//

#ifndef IMS_PROJEKT_CELL_H
#define IMS_PROJEKT_CELL_H

using namespace std;

class cell {
public:
    cell(int id);
    ~cell(void);

    int p; // infected population/ total population
    int inf; //infection flag
    int imf; //immune flag
    int tIn; //time infected
    int tIm; //time immune

};


#endif //IMS_PROJEKT_CELL_H
