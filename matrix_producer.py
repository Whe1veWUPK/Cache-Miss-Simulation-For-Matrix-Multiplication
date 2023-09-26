import numpy as np
import os
"""随机生成的矩阵的数值范围 0-100"""
MAXNUM = 100
MINNUM = 0
"""设置矩阵文件生成路径"""
path = os.getcwd()

def constructMatrix(num,filename):
    """根据传入的行列数 以及文件名称 生成随机矩阵 并将矩阵存入对应的 txt中"""
    randomMatrix=np.random.randint(MINNUM,MAXNUM,(num,num))
    np.savetxt(path+r'\\'+filename+r'.txt',randomMatrix,fmt="%d",delimiter=' ')


matrixA = input("Please input the matrix's name: ")
sizeOfA = input("Please input the matrix's row's size: ")
sizeOfA = int(sizeOfA)
matrixB = input("Pleass input the matrix's name: ")
sizeOfB = input("Please input the matrix's row's size: ")
sizeOfB = int(sizeOfB) 
constructMatrix(sizeOfA,matrixA)
constructMatrix(sizeOfB,matrixB)