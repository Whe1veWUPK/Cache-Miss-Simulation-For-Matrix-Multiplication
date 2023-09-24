#include<iostream>
#include "Cache.hpp"
#include "MatrixElement.hpp"
#include "ReadMatrix.hpp"

int **matrixA;
int **matrixB;
void testIJK(Cache myCache){
    int size = getLines("A.txt");
    int missNum = 0;
    int w = myCache.getWidth();
    int theoryMissNum = (size * size * size / w) * (1 / size + 1 + w);
    //initial matrixC
    int **matrixC = new int *[size];
    for (int i = 0; i < size;++i){
        matrixC[i] = new int[size];
    }
    for (int i = 0; i < size;++i){
        for (int j = 0; j < size;++j){
            matrixC[i][j] = -1;
        }
    }
    //do matrix multiple in "ijk" order
    for (int i = 0; i < size;++i){
        for (int j = 0; j < size;++j){
            for (int k = 0; k < size;++k){
                //read matrixA
                MatrixElement tempA("A", i, k, matrixA[i][k]);
                if(!myCache.query(tempA)){
                    //not find
                    ++missNum;
                    //then insert
                    MatrixElement *block = new MatrixElement[w];
                  
                }
            }
        
        }
    }
}
void testIKJ(Cache myCache){

}

void finalTest(){
    // 为 矩阵A 和 矩阵 B 申请内存 并且初始化数据
    int sizeA = getLines("A.txt");
    int sizeB = getLines("B.txt");
    matrixA = new int *[sizeA];
    matrixB = new int *[sizeB];
    for (int i = 0; i < sizeA;++i){
        matrixA[i] = new int[sizeA];
    }
    for (int i = 0; i < sizeB;++i){
        matrixB[i] = new int[sizeB];
    }
    for (int i = 0; i < sizeA;++i){
        for (int j = 0; j < sizeA;++j){
            matrixA[i][j] = -1;
        }
    }
    for (int i = 0; i < sizeB;++i){
        for (int j = 0; j < sizeB;++j){
            matrixB[i][j] = -1;
        }
    }
    // 矩阵数据从 disk -> main memory
    readMatrix("A.txt", matrixA);
    readMatrix("B.txt", matrixB);
    
    std::cout << "Please input the line's width of the Cache"
              << "\n";
    int width;
    std::cin >> width;
    std::cout << "Please input the num of lines of the Cache"
              << "\n";
    int numOfLines;
    std::cin >> numOfLines;
    Cache cache(width, numOfLines);
    testIJK(cache);
    testIKJ(cache);
}
int main(){
    finalTest();
    system("pause");
    return 0;
}