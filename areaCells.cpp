/*
 * IMS Project - Application of celular automata in biology
 * Authors: Filip Gulan and Marek Marusic
 * E-mails: xgulan00@stud.fit.vutbr.cz and xmarus05@stud.fit.vutbr.cz
 */

#include <iostream>
#include <unistd.h>
#include "areaCells.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*
 * Constructor of class
 * @width of automata
 * @deathTime time of plant death
 * @vegetationTime time of vegetaation of plant
 * @seedRain probability of random seed occur
 * @extiction probability of death
 * @Time to finish simulation
 * @intenseExct bigger probability of death, intensity
 */
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

/*
 * Method, that fill empty matrix with data
 */
void areaCells::fillMatrix()
{
    cell tmpCell;
    for(int i = 0; i < width; i++) //for row in matrix
    {
        for(int j = 0; j < width; j++) //for col in matrix
        {
            tmpCell.setData(i, j, EMPTY);
            matrixPresent.push_back(tmpCell);
            matrixFuture.push_back(tmpCell);
        }
    }
    matrixPresent[(width/2) + (width/2) * width].state = 1;
}

/*
 * Method, that fills matrix with plants at various age stage
 */
void areaCells::fillWithPlants()
{
    for(int i = 0; i < width; i++) //for row in matrix
    {
        for(int j = 0; j < width; j++) //for col in matrix
        {
            matrixPresent[i + j * width].state = i % deathTime;
        }
    }
}

/*
 * Method, that creates stone at certain position
 */
void areaCells::fillRock() 
{
    int size = width/4;
    int start = width/4;
    //int randomNumber = size/2;
    for(int i = start; i < start+size; i++)
    {
        for(int j = start; j < start+size; j++)
        {
            //int diery = rand() % size + 1;
            //if(diery > 0 && diery < randomNumber)
            //    continue;
            this->matrixPresent[i + j * this->width].setState(STONE);
        }
    }
}

/*
 * Method, that evolves all cells and update matrix with new ones
 */
void areaCells::updateMatrices()
{
    cell temp;
    int population = NOPOPULATION;
    for(int i = 0; i < this->width; i++) //for row in matrix
    {
        for(int j = 0; j < this->width; j++) //for col in matrix
        {
            this->evolve(i, j);
        }
    }

    //Copy the Future matrix to Present matrix after calculations
    for(int i = 0; i < this->width; i++) //row
    {
        for(int j = 0; j < this->width; j++) //col
        {
            temp = this->matrixFuture[i + j * this->width];
            this->matrixPresent[i + j * this->width].setState(temp.state);
            if(temp.state > EMPTY) //cell is no empty
            {
                population++;
            }
        }
    }

    populationPercent = population/((double)width * (double)width) * 100; //count percentage of population of matrix
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
    if(matrixPresent[i + j * width].state == EMPTY) //empty cell
    {
        if((vegetationTime != -1) && (getNeighborsState(i + 1, j) == vegetationTime || getNeighborsState(i - 1, j) == vegetationTime || getNeighborsState(i, j + 1) == vegetationTime || getNeighborsState(i, j - 1) == vegetationTime)) //vegetation enabled and has any neighbour in vegetation time
        {
            matrixFuture[i + j * width].state = NEWPLANT;
        }
        else //stil chance to plant, seed rain
        {
            int randomNumber = rand() % 100 + 1;
            if(randomNumber <= seedRain) //prohability of seed rain
            {
                matrixFuture[i + j * width].state = NEWPLANT;
            }
        }
    }
    else if(matrixPresent[i + j * width].state > EMPTY) //cell contains plant
    {
        int helpState = matrixPresent[i + j * width].state + 1; //next age
        if (helpState > deathTime) //it is time to death
        {
            helpState = EMPTY;
            if ((vegetationTime != -1) && (getNeighborsState(i + 1, j) == vegetationTime || getNeighborsState(i - 1, j) == vegetationTime ||
                getNeighborsState(i, j + 1) == vegetationTime ||
                getNeighborsState(i, j - 1) == vegetationTime))
            {
                helpState = NEWPLANT;
            }
            else //seed rain
            {
                int randomNumber = rand() % 100 + 1;
                if (randomNumber <= seedRain)
                {
                    helpState = NEWPLANT;
                }
            }
        }
        else //plant live, but also probability to death
        {
            int randomNumber = rand() % 100 + 1;
            if (randomNumber <= extiction) //extiction probability
            {
                helpState = EMPTY;
                if ((vegetationTime != -1) && (getNeighborsState(i + 1, j) == vegetationTime || getNeighborsState(i - 1, j) == vegetationTime || getNeighborsState(i, j + 1) == vegetationTime || getNeighborsState(i, j - 1) == vegetationTime)) //empty cell
                {
                    helpState = NEWPLANT;
                }
                else //seed rain
                {
                    int randomNumber = rand() % 100 + 1;
                    if (randomNumber <= seedRain)
                    {
                        helpState = 1;
                    }
                }
            }
            else if (currentTime == Time / 2 && intenseExct > 0 && randomNumber <= intenseExct) //intensive extiction enabled
            {
                helpState = EMPTY;
            }
        }
        matrixFuture[i + j * width].state = helpState;
    }
    else if(matrixPresent[i + j * width].state == STONE) //stone stay always same
    {
        matrixFuture[i + j * width].state = STONE;
    }
}

/*
 * Method, to get neighboors State on i, j coordinates in torus like surface
 * @i position
 * @j position
 * RETURN: state of cell
 */
int areaCells::getNeighborsState(int i, int j)
{
    if(i < 0) //i is smaller than lower limit
    {
        i = this->width - 1;
    }
    else if(i >= this->width) //i is bigger than upper limit
    {
        i = 0;
    }
    if(j < 0) //j is smaller than lower limit
    {
        j = this->width - 1;
    }
    else if(j >= this->width) //j is bigger than upper limit
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
    for(int i = 0; i < this->width; i++) //for row in matrix
    {
        for (int j = 0; j < this->width; j++) //for col in matrix
        {
            if(this->matrixPresent[i + j * this->width].state > EMPTY) //cell contain plant
            {
                cout << "\033[1;32m" << this->matrixPresent[i + j * this->width].state  << " \033[0m ";
            }
            else if(this->matrixPresent[i + j * this->width].state == EMPTY) //cell is vacant
            {
                cout << "\033[1;35m- \033[0m ";
            }
            else //cell contain stone
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

/*
 * Method, that makes new lines at then end of comand line visualisation
 */
void areaCells::endShowCmd(void)
{
    for(int i = 0; i < this->width; i++)
    {
        cout << endl;
    }
}

/*areaCells::~areaCells(void) {

}*/
