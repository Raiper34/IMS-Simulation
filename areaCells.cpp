//
// Created by marek on 11/21/15.
//

#include "areaCells.h"

areaCells::areaCells(int width, int infectionTime, int imunityTime) {
    this->width = width;
    time = 0;
    this->infectionTime = infectionTime;
    this->imunityTime = imunityTime;
    matrixPresent.reserve(this->width);
    matrixFuture.reserve(this->width);
}

void areaCells::fillMatrix(void){
    cell tmpCell;
    tmpCell.setData(0,0,0,0,0,this->width);
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->width; j++){
            tmpCell.setPostion(i,j);
            this->matrixPresent.push_back(tmpCell);
            this->matrixFuture.push_back(tmpCell);
        }
    }
}

void areaCells::updateMatrices(void){
    cell temp;
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->width; j++){
            this->evolve(i, j);
        }
    }

    //Copy the Future matrix to Present matrix after calculations
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->width; j++){
            //TODO: Check me
            this->matrixPresent[i + j + this->width] = this->matrixFuture[i + j + this->width];

            temp = this->matrixFuture[i + j + this->width];
            this->matrixPresent[i + j + this->width].setData(temp.popSick, )
        }
    }
}

/*
 * Evolve cell to next stage depends on rules
 * @i   vertical position in vector
 * @j   horizontal position in vector
 */
void areaCells::evolve(int i, int j)
{
    //todo vzorecek

    this->matrixPresent[i + j * this->width];
}

void areaCells::getPopSick(int i, int j)
{
    
}

areaCells::~areaCells(void) {

}
