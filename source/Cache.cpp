#include<iostream>
#include "MatrixElement.h"
#include "Cache.h"

Cache::Cache(int width,int numOfLines){
    setCache(width, numOfLines);
}
void Cache::setCache(int width,int numOfLines){
    this->width = width;
    this->numOfLines = numOfLines;
}
void Cache::setWidth(int width){
    this->width = width;
}
void Cache::setNumOfLines(int numOfLines){
    this->numOfLines = numOfLines;
}
int Cache::getWidth(){
    return this->width;
}
int Cache::getNumOfLines(){
    return this->numOfLines;
}
void Cache::initial(){
    this->cache = new MatrixElement *[this->numOfLines];
    for (int i = 0; i < this->numOfLines;++i){
        //this->cache[i] = new MatrixElement[this->width];
    }
    for (int row = 0; row < this->numOfLines;++row){
        for (int col = 0; col < this->width;++col){
            MatrixElement temp("None", -1, -1, -1);
            this->cache[row][col] = temp;
        }
    }
}
