#ifndef __READMATRIX_HPP__
#define __READMATRIX_HPP__

int getLines(std::string filepath); //得到矩阵的规模大小
void readMatrix(std::string filepath,int**matrix); //从文件中读取矩阵到内存中

#endif