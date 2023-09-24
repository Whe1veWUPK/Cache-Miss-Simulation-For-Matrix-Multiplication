#include<iostream>
#include "Cache.hpp"
#include "MatrixElement.hpp"
#include "ReadMatrix.hpp"

int **matrixA;
int **matrixB;
void testIJK(Cache myCache){
    int n = getLines("A.txt");
    int missNum = 0;
    int w = myCache.getWidth();
    int theoryMissNum = (n * n * n / w) * (1 / n + 1 + w);
    //initial matrixC
    int **matrixC = new int *[n];
    for (int i = 0; i < n;++i){
        matrixC[i] = new int[n];
    }
    for (int i = 0; i < n;++i){
        for (int j = 0; j < n;++j){
            matrixC[i][j] = -1;
        }
    }
    //do matrix multiple in "ijk" order
    for (int i = 0; i < n;++i){
        for (int j = 0; j < n;++j){
            for (int k = 0; k < n;++k){
                //read matrixA
                MatrixElement tempA("A", i, k, matrixA[i][k]);
                if(!myCache.query(tempA)){
                    // std::cout << "false"
                    //           << "\n";
                    //not find
                    ++missNum;
                    //then insert
                    int insertSize = std::min(w, n - k); //这里取Cache行宽和主存一行剩余数据的长度的最小值作为插入的size 这样可以确保不会换行
                    MatrixElement *insertBlock = new MatrixElement[w];
                    for (int i1 = 0; i1 < w;++i1){
                        if(i1<insertSize){
                             insertBlock[i1] = MatrixElement("A", i, i1 + k, matrixA[i][i1 + k]);
                        }
                        else{//剩余部分插入空数据
                             insertBlock[i1] = MatrixElement("None", -1, -1, -1);
                        }
                    }
                    myCache.insert(insertBlock);
                }
                //read matrixB
                MatrixElement tempB("B", i, k, matrixB[k][j]);
                if(!myCache.query(tempB)){
                    //如果没在Cache中找到
                    ++missNum;
                    //插入
                    int insertSize = std::min(w, n - j);//这里取Cache行宽和主存一行剩余数据的长度的最小值作为插入的size
                    MatrixElement *insertBlock = new MatrixElement[w];
                    for (int i1 = 0; i1 < w;++i1){
                        if(i1<insertSize){
                             insertBlock[i1] = MatrixElement("B", k, j + i1, matrixB[k][j + i1]);
                        }
                        else{//剩余部分插入空数据
                             insertBlock[i1] = MatrixElement("None", -1, -1, -1);
                        }
                        myCache.insert(insertBlock);
                    }
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