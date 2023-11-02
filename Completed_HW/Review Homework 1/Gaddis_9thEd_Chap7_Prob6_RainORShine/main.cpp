/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  population
 */

//System Libraries#include <iostream>  //Input/output Library
#include <iostream>  //Input/output Library
#include <fstream>   //File Library I/O
#include <cstdlib>   //Random function
#include <ctime>     //Time Library
#include <cstring>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream out1,out2;
    const int SIZE=20;
    char fileNm1[SIZE]="RainOrShine.txt";
    unsigned char nMonths,nDays;
    
    //Initial Variables
    out1.open(fileNm1,ios::out);
    nMonths=3;
    nDays=30;
    
    //Map the Inputs to the Outputs
    for(int month=1;month<=nMonths;month++){
        for(int day=1;day<=nDays;day++){
            char typDay=rand()%3;
            switch(typDay){
                case 0: out1<<'R';
                        cout<<'R';
                        break;
                case 1: out1<<'C';
                        cout<<'C';
                        break;
                case 2: out1<<'S';
                        cout<<'S';
                        break;
            }
        }
        cout<<endl;
        out1<<endl;
    }
    
    //Display the Inputs and Outputs

    //Exit the code
    out1.close();
    return 0;
}
