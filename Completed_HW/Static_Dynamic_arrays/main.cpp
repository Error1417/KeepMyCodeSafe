/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael
 *
 * Created on August 23, 2023, 11:34 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//global constants
const int COLS = 5; // static # of columns


void fillAry(int [],int); //static 1d array fill
int *fillAry(int); // dynamic 1d array fill
void fillAry(int[][COLS],int); // static 2d array fill
int **fillAry(int, int); // dynamic 2d array fill
void prntAry(int[],int, int); // print 1d static or dynamic array
void prntAry(int **, int, int); // print 2d dynamic array
void prntAry(int [][COLS],int); // print 2d static array
void deAlloc(int **, int*, int);

//Execution begins here
int main(int argc, char** argv) {
    //set random seed
    srand(static_cast<unsigned int> (time(0)));
    
    const int SIZE = 100; //constant associated with the static 1d array
    int sAry1D[SIZE]; // static 1d Array
    int *dAry1D; // dynamic pointer to the 1d array
    const int ROWS = 10; // constant for the number of rows
    int sAry2D[ROWS][COLS]; // static 2d array
    int **dAry2D; // dynamic pointer to the 2d array

    
    int size = SIZE, rows = ROWS, cols = COLS;
    fillAry(sAry1D,SIZE);
    dAry1D = fillAry(size);
    fillAry(sAry2D, ROWS);
    dAry2D = fillAry(rows,cols);
    
    //print out
    cout << "Static 1D Array" << endl;
    prntAry(sAry1D,SIZE,10);
    cout << "Dynamic 1D Array" << endl;
    prntAry(dAry1D,SIZE,10);
    
    cout << "Static 2D Array" << endl;
    prntAry(sAry2D,ROWS);
    cout << "Dynamic 2D Array" << endl;
    prntAry(dAry2D,rows,cols);
    
    
    
    //de-allocate memory
    deAlloc(dAry2D,dAry1D,rows);
    

    return 0;
}

void prntAry(int **a, int rows, int cols){
    cout << endl;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void prntAry(int a[][COLS],int rows){
    cout << endl;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<COLS; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void prntAry(int *a,int n, int perline){
    cout << endl;
    for(int i = 0; i<n;i++){
        cout << *(a+i) << " ";
        if (i % perline == (perline -1)) cout << endl;
    }
    cout << endl;
}


void deAlloc(int **da2, int *da1, int rows){
    delete []da1;
    for(int i = 0; i<rows; i++){
        delete []da2[i];   
    }
    delete []da2;
}


void fillAry(int a[],int n){
    for(int i = 0; i<n; i++){
        *(a+i)=rand()% 90 + 10; // [10,99]
    }
}


int *fillAry(int n){
    n=n<2||n>200?2:n;
    int *a = new int[n];
    
    for(int i = 0; i<n; i++){
        a[i] =rand()% 90 + 10; // [10,99]
    }
    return a;
} 


void fillAry(int a[][COLS],int rows){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<COLS; j++){
            *(*(a+i)+j) = rand()% 90+10;// [10,99]
        }
    }
}


int **fillAry(int rows, int cols){
    //making sure dimensions remain in bounds
    rows=rows<2||rows>200?2:rows;
    cols=cols<2||cols>200?2:cols;
    //allocating memory
    int **a =new int *[rows]; //pointer arrat to each row
    
    for(int i= 0; i<rows;i++){
        a[i]=new int[cols];
    }
    //filling memory with data
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<COLS; j++){
            a[i][j] = rand()% 90+10;// [10,99]
        }
    }
    return a;
    
}