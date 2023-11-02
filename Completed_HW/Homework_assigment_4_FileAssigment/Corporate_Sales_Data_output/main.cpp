/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: corperate sales data output
 * Author: Ismael Perez
 * 
 * Created on: october 16 2022
 * 
 * Purpose: 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int SIZE = 4;
const int NAME_SIZE = 50;

struct Info{
    char name[NAME_SIZE];
    float sales[SIZE];
    int quarter[SIZE];
};

int main(int argc, char** argv) {
    Info division[SIZE];
    fstream data("data.txt",ios::in | ios::out);
    
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
            division[i].quarter[j]=j+1;
    }
    
    strcpy(division[0].name,"North");
    strcpy(division[1].name,"East");
    strcpy(division[2].name,"South");
    strcpy(division[3].name,"West");
    
    for(int i=0;i<SIZE;i++){
        
        cout<<division[i].name<<endl;
        for(int j=0;j<SIZE;j++){
            
            cout<<"Enter Quarter "<<division[i].quarter[j]<<" sales:";
            cin >> division[i].sales[j];
            
            if(division[i].sales[j]<0){
                cout << "Negative number received" << endl;
            }
        }
        cout<<endl;
    }
    
    data.write(reinterpret_cast<char*>(&division),sizeof(division));
    data.close();
    
    return 0;
}


