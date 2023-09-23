#ifndef MATRIXELEMENT_H
#define MATRIXELEMENT_H

class MatrixElement{ // 矩阵元素类的声明
private:
    std::string matrix;
    int rowID;
    int colID;
    int value;
public:
    MatrixElement(std::string matrix, int rowID, int colID, int value);// 矩阵元素类的构造函数
    MatrixElement();//矩阵元素类的无参构造函数
    void setMatrixElement(std::string matrix, int rowID, int colID, int value);//矩阵元素类的set函数
    void setMatrix(std::string matrix); //矩阵的set函数
    void setRowID(int rowID); //行坐标的set函数
    void setColID(int colID);//列坐标的set函数
    void setValue(int value);//元素值的set函数
    std::string getMatrix();//矩阵的get函数
    int getRowID();//行坐标的get函数
    int getColID();//列坐标的get函数
    int getValue();//元素值的get函数
}; 
#endif