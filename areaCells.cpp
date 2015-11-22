//
// Created by marek on 11/21/15.
//

#include <iostream>
#include <unistd.h>
#include "areaCells.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

areaCells::areaCells(int width, int infectionTime, int imunityTime) {
    this->width = width;
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

    this->matrixPresent[(this->width/2) + (this->width/2) * this->width].inf = 1; //first sick cell in system
    this->matrixPresent[(this->width/2) + (this->width/2) * this->width].tIn = 2;

    this->showInCmd();
}

void areaCells::updateMatrices(int cmdLine)
{
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
            //this->matrixPresent[i + j * this->width] = this->matrixFuture[i + j + this->width];

            temp = this->matrixFuture[i + j * this->width];
            this->matrixPresent[i + j * this->width].setData(temp.popSick, temp.inf, temp.imf, temp.tIn, temp.tIm);
        }
    }
    if(cmdLine == 1)
        this->showInCmd();
}

/*
 * Evolve cell to next stage depends on rules
 * @i   vertical position in vector
 * @j   horizontal position in vector
 */
void areaCells::evolve(int i, int j)
{
    //todo vzorecek
    if(this->matrixPresent[i + j * this->width].inf == 0 && this->matrixPresent[i + j * this->width].imf == 0)
    {
        if (this->matrixPresent[(i + 1) + j * this->width].inf == 1
            || this->matrixPresent[(i - 1) + j * this->width].inf == 1
            || this->matrixPresent[i + (j - 1) * this->width].inf == 1
            || this->matrixPresent[i + (j + 1) * this->width].inf == 1
            || this->matrixPresent[(i + 1) + (j + 1) * this->width].inf == 1
            || this->matrixPresent[(i + 1) + (j - 1) * this->width].inf == 1
            || this->matrixPresent[(i - 1) + (j + 1) * this->width].inf == 1
            || this->matrixPresent[(i - 1) + (j - 1) * this->width].inf == 1)
        {
            //srand(NULL);
            int randomNumber = rand() % 10 + 1;
            if (randomNumber > 5)
            {
                this->matrixFuture[i + j * this->width].inf = 1;
                this->matrixFuture[i + j * this->width].tIn = 2;

            }
        }
    }
    else if(this->matrixPresent[i + j * this->width].inf == 1)
    {
        this->matrixFuture[i + j * this->width].tIn--;
        if(this->matrixFuture[i + j * this->width].tIn == 0)
        {
            this->matrixFuture[i + j * this->width].imf = 1;
            this->matrixFuture[i + j * this->width].tIm = 3;
            this->matrixFuture[i + j * this->width].inf = 0;
        }
    }
    else if(this->matrixPresent[i + j * this->width].imf == 1)
    {
        this->matrixFuture[i + j * this->width].tIm--;
        if(this->matrixFuture[i + j * this->width].tIm == 0)
        {
            this->matrixFuture[i + j * this->width].imf = 0;
        }
    }
    //this->matrixFuture[i + j * this->width].inf = 1;
    //this->getPopSick(0,0);
    //this->matrixPresent[i + j * this->width];
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
            if(this->matrixPresent[i + j * this->width].inf == 1) //if cell is infected
            {
                cout << "\033[0;31mI \033[0m ";
            }
            else if(this->matrixPresent[i + j * this->width].imf == 1) //cell is imunited
            {
                cout << "\033[0;32mR \033[0m ";
            }
            else //cell is supsceptible
            {
                cout << "\033[0;34mS \033[0m ";
            }
        }
        cout << endl;
    }
    for(int k = 0; k < this->width; k++)
    {
        cout << "\033[F";
        flush(cout);
    }
}

void areaCells::endShowCmd(void)
{
    for(int i = 0; i < this->width; i++)
    {
        cout << endl;
    }
    //cout << endl;
}

areaCells::~areaCells(void) {

}
