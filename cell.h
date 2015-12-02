#ifndef IMS_PROJEKT_CELL_H
#define IMS_PROJEKT_CELL_H

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
