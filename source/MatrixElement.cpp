#include<iostream>
#include "MatrixElement.h"

MatrixElement::MatrixElement(std::string matrix, int rowID, int colID, int value){ 
    setMatrixElement(matrix, rowID, colID, value);
}
void MatrixElement::setMatrixElement(std::string matrix, int rowID, int colID, int value){ 
    setMatrix(matrix);
    setRowID(rowID);
    setColID(colID);
    setValue(value);
}
void MatrixElement::setMatrix(std::string matrix){
    this->matrix = matrix;
}
void MatrixElement::setRowID(int rowID){
    this->rowID = rowID;
}
void MatrixElement::setColID(int colID){
    this->colID = colID;
}
void MatrixElement::setValue(int value){
    this->value = value;
}
std::string MatrixElement::getMatrix(){
    return this->matrix;
}
int MatrixElement::getRowID(){
    return this->rowID;
}
int MatrixElement::getColID(){
    return this->colID;
}
int MatrixElement::getValue(){
    return this->value;
}

