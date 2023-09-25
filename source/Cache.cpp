#include<iostream>

#include "Cache.hpp"

Cache::Cache(int width,int numOfLines){
    setCache(width, numOfLines);
    initial();
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
    //申请内存 并且初始化 Cache
    this->cache = new MatrixElement *[this->numOfLines];
    for (int i = 0; i < this->numOfLines;++i){
        this->cache[i] = new MatrixElement[this->width];
    }
    for (int row = 0; row < this->numOfLines;++row){
        for (int col = 0; col < this->width;++col){
            MatrixElement temp("None", -1, -1, -1);
            this->cache[row][col] = temp;
        }
    }
    // for (int row = 0; row < this->numOfLines;++row){
    //     for (int col = 0; col < this->width;++col){

    //         std::cout << this->cache[row][col].getMatrix() << " ";
    //     }
    //     std::cout << "\n";
    // }
    this->flags = new int[this->numOfLines]; //申请内存并初始化LRU数组
    for (int i = 0; i < this->numOfLines;++i){
        this->flags[i] = 0;
    }
    this->isEmpty = new bool[this->numOfLines];//申请内存并初始化isEmpty数组
    for (int i = 0; i < this->numOfLines;++i){
        this->isEmpty[i] = true;
    }
}
void Cache::insert(MatrixElement*elements){
    //向Cache 中添加一行数据
    int targetLine = -1;//寻找空的目标行 返回第一个为空的空行号
    for (int i = 0; i < this->numOfLines;++i){
        if(this->isEmpty[i]){
            targetLine = i;
            this->isEmpty[i] = false;//该行已不为空
            break;
        }
    }
    //如果Cache已满
    if(targetLine==-1){
        this->replace(elements);
        return;
    }
    this->flags[targetLine] = 0;
    //如果Cache不满 更新其它行的LRU值
    for (int i = 0; i < this->numOfLines;++i){
        if(i!=targetLine){
            this->flags[i] += 1;
        }
    }
    //执行插入操作
    for (int i = 0; i < this->width;++i){
        this->cache[targetLine][i].setMatrix(elements[i].getMatrix());
        this->cache[targetLine][i].setRowID(elements[i].getRowID());
        this->cache[targetLine][i].setColID(elements[i].getColID());
        this->cache[targetLine][i].setValue(elements[i].getValue());
    }
    return;
}
void Cache::replace(MatrixElement*elements){
    int victimLine = -1;
    int temp = -(1 << 30);
    //寻找牺牲行 flags数组中的最大值
    for (int i = 0; i < this->numOfLines;++i){
        if(this->flags[i]>temp){
            temp = this->flags[i];
            victimLine = i; 
        }
    }
    //寻找到牺牲行之后 开始替换
    for (int i = 0; i < this->width;++i){
        this->cache[victimLine][i].setMatrix(elements[i].getMatrix());
        this->cache[victimLine][i].setRowID(elements[i].getRowID());
        this->cache[victimLine][i].setColID(elements[i].getColID());
        this->cache[victimLine][i].setValue(elements[i].getValue());
    }
    //更新flags数值
    this->flags[victimLine] = 0;
    for (int i = 0; i < this->numOfLines;++i){
        if(i!=victimLine){
            this->flags[i] += 1;
        }
    }
}
bool Cache::query(MatrixElement element){
    //提取信息
    std::string matrix = element.getMatrix();
    int rowID = element.getRowID();
    int colID = element.getColID();
    int value = element.getValue();
    bool queryAns = false; //查询结果
    //开始寻找
    for (int i = 0; i < this->numOfLines;++i){
        if(this->isEmpty[i]==false){
            for (int j = 0; j < this->width;++j){
                 if((matrix==this->cache[i][j].getMatrix())&&(rowID==this->cache[i][j].getRowID())&&(colID==this->cache[i][j].getColID())&&(value==this->cache[i][j].getValue())){
                     queryAns = true;  //查询成功
                     //更新flags相关信息
                     this->flags[i] = 0;
                     for (int k = 0; k < this->numOfLines;++k){
                            if(i!=k){
                                this->flags[k] += 1;
                            }
                     }
                    return queryAns;
                 }
            }
        }
    }
    return queryAns; //查询失败
}
// int main(){
//     Cache cache(10, 10);
//     system("pause");
//     return 0;
// }
