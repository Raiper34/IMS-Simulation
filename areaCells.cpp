//
// Created by marek on 11/21/15.
//

#include <iostream>
#include <unistd.h>
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
    tmpCell.setData(0,0,0,0,0);
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
            this->matrixPresent[i + j + this->width].setData(temp.popSick, temp.inf, temp.imf, temp.tIn, temp.tIm);
        }
    }
    //this->showInCmd();
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

int areaCells::getPopSick(int i, int j)
{
    if(i > 0 || j > 0 || i < this->width || j < this->width)
    {
        return(NOEXIST);
    }
    return(this->matrixPresent[i + j + this->width].popSick);
}

/*
 * Method, that show cells status in comandline over time, comandline animation for debug
 */
void areaCells::showInCmd(void)
{
    for(int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            cout << " " << this->matrixPresent[i + j + this->width].inf << " ";
        }
        cout << endl;
    }
    for(int k = 0; k < this->width; k++)
    {
        cout << "\033[F";
    }
    usleep(100000);
}

areaCells::~areaCells(void) {

}
