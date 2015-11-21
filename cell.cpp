//
// Created by marek on 11/21/15.
//

#include "cell.h"

cell::cell(){
    popSick = 0; //Population sickness =  infected population/ total population
    inf = 0;    //infection flag
    imf = 0;    //immune flag
    tIn = 0;    //time infected
    tIm = 0;    //time immune
    i = 0;      //vertical position
    j = 0;      //horizontal position
    width;
};

void cell::setData(int popSick, int inf, int imf, int tIn, int tIm, int width){
    this->popSick = popSick;
    this->inf = inf;
    this->imf = imf;
    this->tIn = tIn;
    this->tIm = tIm;
    this->width = width;
}

void cell::setPostion(int i, int j){
    this->i = i;
    this->j = j;
};

int cell::getPopSick(void)
{

}

cell::~cell(){

};