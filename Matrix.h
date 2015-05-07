
//
//  Matrix.h
//  abc
//
//  Created by hchoi on 4/5/15.
//  Copyright (c) 2015 hchoi. All rights reserved.
//

#ifndef __abc__Matrix__
#define __abc__Matrix__

#include <stdio.h>
#include <iostream>

class Matrix{
    
public:
       
    Matrix(int rowNum, int colNum);
    Matrix(const Matrix &temp );
    
    ~Matrix();
   
    
    int rowSize() { return row; }
    int colSize() { return col; }
    int getEntry(int i, int j);
    void setEntry(int i, int j, int val);
    void printMatrix();
    
    void resize(int newRow, int newCol);
   ;
    Matrix& operator = (const Matrix &b);
    Matrix operator+(  Matrix&b);
    
private:
    int **p;
    int row;
    int col;
    
    
};

#endif /* defined(__abc__Matrix__) */
