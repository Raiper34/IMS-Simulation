/*
 * IMS Project - Application of celular automata in biology
 * Authors: Filip Gulan and Marek Marusic
 * E-mails: xgulan00@stud.fit.vutbr.cz and xmarus05@stud.fit.vutbr.cz
 */

#ifndef IMS_PROJEKT_CELL_H
#define IMS_PROJEKT_CELL_H

#define EMPTY 0

using namespace std;

class cell {
public:
    cell();
    void setData(int i, int j, int state);
    void setState(int state);
    int i;
    int j;
    int state;
    //~cell(void);
};


#endif //IMS_PROJEKT_CELL_H
