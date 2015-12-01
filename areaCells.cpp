//
// Created by marek on 11/21/15.
//

#include <iostream>
#include <unistd.h>
#include "areaCells.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

areaCells::areaCells(int width, int deathTime, int vegetationTime, int seedRain, int extiction)
{
    this->width = width;
    this->deathTime = deathTime;
    this->vegetationTime = vegetationTime;
    this->extiction = extiction;
    this->seedRain = seedRain;

    matrixPresent.reserve(this->width);
    matrixFuture.reserve(this->width);
}

void areaCells::fillMatrix(int cmdLine){
    cell tmpCell;
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->width; j++){
            tmpCell.setData(i, j, 0);
            this->matrixPresent.push_back(tmpCell);
            this->matrixFuture.push_back(tmpCell);
        }
    }

    /*if(cmdLine == 1)
        this->showInCmd();*/
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
            temp = this->matrixFuture[i + j * this->width];
            this->matrixPresent[i + j * this->width].setState(temp.state);
        }
    }

    /*if(cmdLine == 1)
        this->showInCmd();*/
}

/*
 * Evolve cell to next stage depends on rules
 * @i   vertical position in vector
 * @j   horizontal position in vector
 */
void areaCells::evolve(int i, int j)
{

}



/*
 * Method, that show cells status in comandline over time, comandline animation for debug
 */
void areaCells::showInCmd(void)
{
    /*for(int i = 0; i < this->width; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if(this->matrixPresent[i + j * this->width].inf == 1) //if cell is infected
            {
                cout << "\033[1;31mI \033[0m ";
            }
            else if(this->matrixPresent[i + j * this->width].imf == 1) //cell is imunited
            {
                cout << "\033[1;32mR \033[0m ";
            }
            else if(this->matrixPresent[i + j * this->width].vac == 1) //cell is vacinated
            {
                cout << "\033[0;37mV \033[0m ";
            }
            else //cell is supsceptible
            {
                cout << "\033[1;34mS \033[0m ";
            }
        }
        cout << endl;
    }
    for(int k = 0; k < this->width; k++)
    {
        cout << "\033[F";
        flush(cout);
    }*/
}

void areaCells::endShowCmd(void)
{
    /*for(int i = 0; i < this->width; i++)
    {
        cout << endl;
    }*/
    //cout << endl;
}

areaCells::~areaCells(void) {

}
