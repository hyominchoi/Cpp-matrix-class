//
//  Matrix.cpp
//  abc
//
//  Created by hchoi on 4/5/15.
//  Copyright (c) 2015 hchoi. All rights reserved.
//

#include "Matrix.h"

Matrix::Matrix(int rowNum, int colNum) {
    p = new int *[rowNum];
    for(int i = 0; i < rowNum; ++i) {
        p[i] = new int[colNum];
        
    }
    row = rowNum;
    col = colNum;
  
    std::cout << " constructor called" << std::endl;
}



Matrix::Matrix(const Matrix &temp){
    row = temp.row;
    col = temp.col;
    
    p = new int *[row];
    
    for(int i = 0; i < row; ++i) {
        p[i] = new int[col];
        
    }
    
    for (int i = 0; i < row; ++i) {
        
        for (int j = 0 ; j < col ; ++j ){
            p[i][j] = temp.p[i][j];
        }
        
    }
    
    
}




Matrix& Matrix:: operator = (const Matrix &b) {
    if (rowSize()!=b.row || colSize()!=b.col) {
        this->resize(b.row, b.col);
        
    }
    
    **p = **b.p;
    
    
    return (*this);
    
}



Matrix Matrix::operator+( Matrix & a){
      
    if (a.rowSize()!= this->rowSize()|| a.rowSize() != this->colSize() ) {
        std:: cout << "Sizes are different" << std:: endl;
        return *this;
    }
    
    Matrix b(rowSize(),colSize());
    
    for ( int i = 0 ; i < a.rowSize(); ++i ) {
        for (int j = 0; j < a.colSize(); ++j ) {
            std::cout << a.p[i][j];
            b.p[i][j] = this->p[i][j]+ a.p[i][j];
            
        }
    }
    
    return b;
    
}


int Matrix::getEntry( int i,  int j) {
    if (i >= rowSize() || j >= colSize() || i < 0 || j < 0) {
        std::cout << "Wrong index, matrix size is not matching" << std::endl;
        return 00;
    }
 
    else {
 
        return p[i][j];
 
    }
 
 }
 
 void Matrix::setEntry( int i, int j, int val) {
 
     if (i >= rowSize() || j >= colSize() || i < 0 || j < 0) {
         std::cout << "Wrong index, matrix size is not matching" << std::endl;
         return;
     }
 
     else {
        p[i][j] = val;
     }
 
 }

void Matrix::printMatrix() {
    
    for (int i = 0 ; i < rowSize(); ++i ) {
        for (int j = 0 ; j < colSize(); ++j) {
            
            std::cout << p[i][j] << " " ;
            
        }
        std::cout << std::endl;
    }
    
    
}



Matrix::~Matrix() {
   for (int i = 0; i < row; ++i ) {
        delete[] p[i];
      
    }
    delete[] p;
 
 }


void Matrix::resize(int newRow, int newCol) {  //for now, resizing does not require copying values

    int **pp ;
    pp = new int *[newRow];
    for (int i = 0; i < newRow; ++i) {
        pp[i] = new int[newCol];
    }
        
    for (int i = 0; i < rowSize(); ++i){
        delete[] p[i];
    }
    delete[] p;
        
    p = pp;
        
    row = newRow;
    col = newCol;
    
}






