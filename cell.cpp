//
// Created by marek on 11/21/15.
//

#include "cell.h"

cell::cell(int id){
    cellId = id;
    S = 1;      //every cell is healthy at the start
    I = 0;           //Inficated and sick
    R = 0;                  //Recovered
    incubationTime = 0;     //Doba inkubacie
    sicknessTime = 0;       //Doba choroby
};

cell::~cell(){

};