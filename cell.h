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
    int cellId;
    int S;                  //Susceptible - healthy cell
    int I;                  //Inficated and sick
    int R;                  //Recovered
    int incubationTime;     //Doba inkubacie
    int sicknessTime;       //Doba choroby
};


#endif //IMS_PROJEKT_CELL_H
