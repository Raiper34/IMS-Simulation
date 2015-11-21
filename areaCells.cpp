//
// Created by marek on 11/21/15.
//

#include "areaCells.h"
areaCells::areaCells(int size) {
    width = a;
    time = 0;
    matrixPresent.reserve(width);
    matrixFuture.reserve(width);
}

areaCells::fillMatrix(){
    cell tmpCell;
    for(int i = 0; i < this->width; i++){
        for(int j = 0; j < this->width; j++){
            this->matrixPresent.push_back(tmpCell);
            this->matrixFuture.push_back(tmpCell);
        }
    }
}

areaCells::updateMatrices(){

}

areaCells::~areaCells(void) {

}
