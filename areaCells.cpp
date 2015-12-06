//
// Created by marek on 11/21/15.
//

#include <iostream>
#include <unistd.h>
#include "areaCells.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

areaCells::areaCells(int width, int deathTime, int vegetationTime, int seedRain, int extiction, int Time, int intenseExct)
{
    this->width = width;
    this->deathTime = deathTime - 1;
    this->vegetationTime = vegetationTime - 1;
    this->extiction = extiction;
    this->seedRain = seedRain;
    this->intenseExct = intenseExct;
    populationPercent = 1/width*width;
    currentTime = 0;
    this->Time = Time;
    ocuppiedPercent.reserve(Time);
    ocuppiedPercent.push_back(populationPercent);

    matrixPresent.reserve(this->width);
    matrixFuture.reserve(this->width);
}

void areaCells::fillMatrix(){
    cell tmpCell;
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->width; j++){
            tmpCell.setData(i, j, 0);
            this->matrixPresent.push_back(tmpCell);
            this->matrixFuture.push_back(tmpCell);
        }
    }

    matrixPresent[(width/2) + (width/2) * width].state = 1;
}

void areaCells::fillWithPlants()
{
    for(int i = 0; i < this->width; i++)
    {
        for(int j = 0; j < this->width; j++)
        {
            matrixPresent[i + j * width].state = i % deathTime;
        }
    }
}

void areaCells::updateMatrices()
{
    cell temp;
    int population = 0;
    for(int i = 0; i < this->width; i++)
    {
        for(int j = 0; j < this->width; j++)
        {
            this->evolve(i, j);
        }
    }

    //Copy the Future matrix to Present matrix after calculations
    for(int i = 0; i < this->width; i++)
    {
        for(int j = 0; j < this->width; j++)
        {
            temp = this->matrixFuture[i + j * this->width];
            this->matrixPresent[i + j * this->width].setState(temp.state);
            if(temp.state > 0)
            {
                population++;
            }
        }
    }
    populationPercent = population/((double)width * (double)width) * 100;
    this->ocuppiedPercent.push_back(populationPercent);
    currentTime++;
}

/*
 * Evolve cell to next stage depends on rules
 * @i   vertical position in vector
 * @j   horizontal position in vector
 */
void areaCells::evolve(int i, int j)
{
    if(matrixPresent[i + j * width].state == 0) //empty
    {
        if((vegetationTime != -1) && (getNeighborsState(i + 1, j) == vegetationTime || getNeighborsState(i - 1, j) == vegetationTime || getNeighborsState(i, j + 1) == vegetationTime || getNeighborsState(i, j - 1) == vegetationTime)) //empty cell
        {
            matrixFuture[i + j * width].state = 1;
        }
        else
        {
            int randomNumber = rand() % 100 + 1;
            if(randomNumber <= seedRain)
            {
                matrixFuture[i + j * width].state = 1;
            }
        }
    }
    else if(matrixPresent[i + j * width].state > 0) {
        int helpState = matrixPresent[i + j * width].state + 1;
        if (helpState > deathTime) {
            helpState = 0;
            if ((vegetationTime != -1) && (getNeighborsState(i + 1, j) == vegetationTime || getNeighborsState(i - 1, j) == vegetationTime ||
                getNeighborsState(i, j + 1) == vegetationTime ||
                getNeighborsState(i, j - 1) == vegetationTime)) //empty cell
            {
                helpState = 1;
            }
            else {
                int randomNumber = rand() % 100 + 1;
                if (randomNumber <= seedRain) {
                    helpState = 1;
                }
            }
        }
        else {
            int randomNumber = rand() % 100 + 1;
            if (randomNumber <= extiction) {
                helpState = 0;
                if ((vegetationTime != -1) && (getNeighborsState(i + 1, j) == vegetationTime || getNeighborsState(i - 1, j) == vegetationTime ||
                    getNeighborsState(i, j + 1) == vegetationTime ||
                    getNeighborsState(i, j - 1) == vegetationTime)) //empty cell
                {
                    helpState = 1;
                }
                else {
                    int randomNumber = rand() % 100 + 1;
                    if (randomNumber <= seedRain) {
                        helpState = 1;
                    }
                }
            }
            else if (currentTime == Time / 2 && intenseExct > 0 && randomNumber <= intenseExct) {
                helpState = 0;
            }
        }
        matrixFuture[i + j * width].state = helpState;
    }
}

int areaCells::getNeighborsState(int i, int j)
{
    if(i < 0)
    {
        i = this->width - 1;
    }
    else if(i >= this->width)
    {
        i = 0;
    }
    if(j < 0)
    {
        j = this->width - 1;
    }
    else if(j >= this->width)
    {
        j = 0;
    }
    return(this->matrixPresent[i + j * this->width].state);
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
            if(this->matrixPresent[i + j * this->width].state > 0)
            {
                cout << "\033[1;32m" << this->matrixPresent[i + j * this->width].state  << " \033[0m ";
            }
            else if(this->matrixPresent[i + j * this->width].state == 0)
            {
                cout << "\033[1;35m- \033[0m ";
            }
            else
            {
                cout << "\033[1;34mO \033[0m ";
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
