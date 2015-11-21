//
// Created by marek on 11/21/15.
//

#ifndef IMS_PROJEKT_CELL_H
#define IMS_PROJEKT_CELL_H

using namespace std;

class cell {
public:
    cell(void);
    ~cell(void);

    int popScik; //Population sickness =  infected population/ total population
    int inf;    //infection flag
    int imf;    //immune flag
    int tIn;    //time infected
    int tIm;    //time immune
    int i;      //vertical position
    int j;      //horizontal position
};


#endif //IMS_PROJEKT_CELL_H
