/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: file head program
 * Author: Ismael Perez
 * 
 * Created on: october 16 2022
 * 
 * Purpose: 
 */


#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    string word;
    fstream file;
    int numOfLines = 0;
    string fileName;
    cout << "Enter filename (ex. data.txt)" << endl;
    cin  >> fileName;
    
    file.open(fileName,	ios::in | ios::out);

    if(!file.is_open())return -1;
    // the file only has the word data with numbers in front of them
    while(getline(file, word) && numOfLines < 10){
        cout << word <<endl;     
        numOfLines++;
    }
    
    file.close();
    
    return 0;
}


