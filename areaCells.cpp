//
// Created by marek on 11/21/15.
//

#include "areaCells.h"

areaCells::areaCells(int size) {
    width = size;
    time = 0;
    matrixPresent.reserve(width);
    matrixFuture.reserve(width);
}

void areaCells::fillMatrix(void){
    cell tmpCell;
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->width; j++){
            this->matrixPresent.push_back(tmpCell);
            this->matrixFuture.push_back(tmpCell);
        }
    }
}

void areaCells::updateMatrices(void){

}

/*
 * Evolve cell to next stage depends on rules
 * @i   vertical position in vector
 * @j   horizontal position in vector
 */
void areaCells::evolve(int i, int j)
{

}

areaCells::~areaCells(void) {

}
