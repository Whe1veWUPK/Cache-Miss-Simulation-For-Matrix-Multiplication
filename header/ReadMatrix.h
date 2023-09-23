#ifndef __READMATRIX_H__
#define __READMATRIX_H__

int getLines(std::string filepath); //得到矩阵的规模大小
int **readMatrix(std::string filepath); //从文件中读取矩阵到内存中

#endif