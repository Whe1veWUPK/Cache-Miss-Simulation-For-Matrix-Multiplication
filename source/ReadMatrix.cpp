#include <iostream>
#include <fstream>
#include <sstream>
#include "ReadMatrix.h"
//从文件中读取矩阵的源文件 内部有函数的具体定义 （Disk -> MainMemory）


int getLines(std::string filepath){
    //获取文件的行数 为规划动态内存做准备
    std::fstream fin(filepath, std::ios::in);
    if (!fin)
    {
        std::cerr << "Can not open the file"
                  << "\n";
   }
   char c;
   int lineCount = 0;
   while(fin.get(c)){
      if(c=='\n'){
          ++lineCount;
      }
   }
   return lineCount;
}
int **readMatrix(std::string filepath){
    //从文件中读取矩阵到内存中 
    int**matrix;
    int size = getLines(filepath);
    matrix = new int *[size];
    for (int i = 0; i < size;++i){
      matrix[i] = new int[size];
    }
    std::fstream fin(filepath, std::ios::in);
    if(!fin){
      std::cerr << "Can not open the file"
                << "\n";
    }
    std::string line;
    int i = 0;
    while(std::getline(fin,line)){
      std::istringstream iss(line);
      int n;
      int j = 0;
      while(iss>>n){
          matrix[i][j] = n;
          ++j;
      }
      ++i;
    }
    // for (int i = 0; i < size;++i){
    //   for (int j = 0; j < size;++j){
    //       std::cout << matrix[i][j] << " ";
    //   }
    //   std::cout << "\n";
    // }
      return matrix;
}


