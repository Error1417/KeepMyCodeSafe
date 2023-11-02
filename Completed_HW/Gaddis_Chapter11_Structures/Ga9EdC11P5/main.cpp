/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Created on October 5
 * Purpose:  Yearly Weather Statistics
 *           
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
const int NUM_MONTHS=12;        //Number of months

//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
enum Months{
    January,Feburary, March, April,May, June, July, August, September,October, November, December
};

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Months month;                   //Months enumerated
    float rain[NUM_MONTHS],         //Rainfall
          highT[NUM_MONTHS],        //High temp
          lowT[NUM_MONTHS];         //Low temp
    float avgR, // Average rain
          avgT, // Average temperature       
          highsT, // highest temperature
          lowsT; // lowest temperature  
          
    //Initialize Variables
    highsT=-1000;                  
    lowsT=1000;                    
    avgR=0;
    avgT=0;                    
    
    //Process or map Inputs to Outputs
    for (month=January; month<=December; month= static_cast<Months>(month+1)){   
        while(cin>>rain[month]){    
            //Rainfall
            cout<<"Enter the total rainfall for the month:"<<endl;
            avgR+=rain[month];          
            
            //High Temp
            cout<<"Enter the high temp:"<<endl;
            cin>>highT[month];          
            avgT+=highT[month];         
            if (highT[month]>highsT)highsT=highT[month];    
            
            //Low Temp
            cout<<"Enter the low temp:"<<endl;
            cin>>lowT[month];           
            avgT+=lowT[month];          
            if (lowT[month]<lowsT)lowsT=lowT[month];        
        }
    }
    
    //Calculate Averages
    avgR=(avgR*2)/month;
    avgT=avgT/month;
    
    //Display Outputs
    cout<<"Average monthly rainfall:"<<fixed<<setprecision(2)<<avgR<<endl;
    cout<<"High Temp:"<<fixed<<setprecision(0)<<highsT<<endl;
    cout<<"Low Temp:"<<lowsT<<endl;
    cout<<"Average Temp:"<<fixed<<setprecision(1)<<avgT;
 
    return 0;
}

