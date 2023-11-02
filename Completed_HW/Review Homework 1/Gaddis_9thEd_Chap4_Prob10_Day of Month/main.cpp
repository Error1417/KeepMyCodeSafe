/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Days in month 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) 
{
    //Set the random number seed
    
    //Declare Variables
    int mnth, //months
        yar; // Years
    
    //Initialize or input i.e. set variable values
    cout << "Days in a month calculator" << endl;
    cout << "Enter in a month(format: 1-12)" << endl;
    cin >> mnth;
    cout << "Enter in a year(format: XXXX)" << endl;
    cin >> yar;
    //Map inputs -> outputs
    switch(mnth){
        case 1:
            cout << "31 Days" << endl;
            break;
        case 2:
            if(yar%400==0)     cout << "29 Days" << endl;

            else if(yar%100==0)cout << "28 Days" << endl;

            else if(yar%4==0)  cout << "29 Days" << endl;
            
            else               cout << "28 Days" << endl;
            break;
            
        case 3:
            cout << "31 Days" << endl;
            break;
        case 4:
            cout << "30 Days" << endl;
            break;
        case 5:
            cout << "31 Days" << endl;
            break;
        case 6:
            cout << "30 Days" << endl;
            break;
        case 7:
            cout << "31 Days" << endl;
            break;
        case 8:
            cout << "31 Days" << endl;
            break;
        case 9:
            cout << "30 Days" << endl;
            break;
        case 10:
            cout << "31 Days" << endl;
            break;
        case 11:
            cout << "30 Days" << endl;
            break;
        case 12:
            cout << "31 Days" << endl;
            break; 
        default:
            cout<< "WRONG INPUT!!!!" << endl;
            break;
    }

    //Display the output
    
    //Exit stage right or left!
    return 0;
}
