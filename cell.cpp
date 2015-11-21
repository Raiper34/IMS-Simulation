//
// Created by marek on 11/21/15.
//

#include "cell.h"

cell::cell(void){
    int popScik = 0; //Population sickness =  infected population/ total population
    int inf = 0;    //infection flag
    int imf = 0;    //immune flag
    int tIn = 0;    //time infected
    int tIm = 0;    //time immune
    int i = 0;      //vertical position
    int j = 0;      //horizontal position
};

void cell::setData(int popScik, int inf, int imf, int tIn, int tIm){
    this->popScik = popScik;
    this->inf = inf;
    this->imf = imf;
    this->tIn = tIn;
    this->tIm = tIm;
}

void cell::setPostion(int i, int j){
    this->i = i;
    this->j = j;
};

cell::~cell(){

};