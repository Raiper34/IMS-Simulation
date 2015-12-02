//
// Created by marek on 11/21/15.
//

#include "cell.h"

cell::cell()
{
    i = 0;
    j = 0;
    state = 0;
};

void cell::setData(int i, int j, int state)
{
    this->i = i;
    this->j = j;
    this->state = state;
}

void cell::setState(int state)
{
    this->state = state;
}

/*cell::~cell(){

};*/