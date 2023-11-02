/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: file display program
 * Author: Ismael Perez
 * 
 * Created on: october 16 2022
 * 
 * -----Broken-------
 * Only shows the first 24 lines of the file
 */


#include <iostream>
#include <fstream>
using namespace std;

void output(int,string,string);

int main()
{
    string word;
    int numLin = 0;
    fstream file;
    string fileName;
    char choice;
    
    
    cout << "Enter filename (ex. data.txt)" << endl;
    cin  >> fileName;

    // the file only has the word data with numbers in front of them
    
    cout << "Would you like to see 24 lines of content of the file? Y/N" << endl;
    cin >> choice;
    
    
    // keeps repeating the first 24 lines and not the rest
    while(choice == 'y' || choice == 'Y'){
        output(numLin,word,fileName);
        cout << "would you like to see another 24 lines? Y/N" << endl;
        cin >> choice;
    }
    
    file.close();
    
    return 0;
}


void output(int numLin, string word, string fileName){
    fstream file;
    file.open(fileName,	ios::in | ios::out);
    
    while(getline(file, word) && numLin < 24){
        cout << word <<endl;     
        numLin++;
    }
}
