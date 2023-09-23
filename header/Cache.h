#ifndef CACHE_H
#define CACHE_H
class Cache{
private:
    int width;//Cache的行宽
    int numOfLines;//Cache的行数
    int *flags;  //LRU 算法所需要的记录flag
    bool *isEmpty;   //记录某一行是否为空 

public:
    MatrixElement**cache;//模拟Cache
    Cache(int width, int numOfLines);     // Cache类的 构造函数
    void setCache(int width, int numOfLines); //Cache 类的 set函数
    void setWidth(int width); //Cache 行宽的set函数
    void setNumOfLines(int numOfLines); //Cache 行数的 set函数
    int getWidth(); //Cache 行宽的get函数
    int getNumOfLines(); //Cache 行数的get函数
    void initial();      // Cache类的 初始化函数
    void insert(MatrixElement *elements); // Cache类的 insert函数
    void replace(MatrixElement *elements); //Cache类的 replace函数 (满则替换) （根据LRU算法）
    bool query(MatrixElement element);//Cache 类的 query 函数 （访问存放在Cache里面的元素）
};
#endif