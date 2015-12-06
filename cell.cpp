/*
 * IMS Project - Application of celular automata in biology
 * Authors: Filip Gulan and Marek Marusic
 * E-mails: xgulan00@stud.fit.vutbr.cz and xmarus05@stud.fit.vutbr.cz
 */

#include "cell.h"

/*
 * Constructor of class
 */
cell::cell()
{
    i = EMPTY;
    j = EMPTY;
    state = EMPTY;
};

/*
 * Method, to set data
 * @i horizontal position in matrix
 * @j vertical position in matrix
 * @state of cell
 */
void cell::setData(int i, int j, int state)
{
    this->i = i;
    this->j = j;
    this->state = state;
}

/*
 * Method, to set state
 * @state state to set
 */
void cell::setState(int state)
{
    this->state = state;
}

/*cell::~cell(){

};*/