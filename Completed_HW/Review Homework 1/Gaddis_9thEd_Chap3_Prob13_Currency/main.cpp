/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Money converter
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float YEN_PER_DOLLAR = 98.93;
const float EUROS_PER_DOLLAR = 0.74;
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) 
{
    //Set the random number seed
    
    //Declare Variables
    float dollr, //Dollars
          yen, // Yen
          euro; // Euros
    
    //Initialize or input i.e. set variable values
    cout << "Money Converter" << endl;
    cout << "Input Money in Dollars" << endl;
    cin >> dollr;
    
    //Map inputs -> outputs
    yen = dollr* YEN_PER_DOLLAR;
    euro = dollr* EUROS_PER_DOLLAR;
    
    //Display the output
    cout << fixed << setprecision(2) << showpoint;
    cout << dollr << " Dollars is equal to " << endl;
    cout << yen << " Yen" << endl;
    cout << euro << " Euros" << endl;
    
    
    //Exit stage right or left!
    return 0;
}
