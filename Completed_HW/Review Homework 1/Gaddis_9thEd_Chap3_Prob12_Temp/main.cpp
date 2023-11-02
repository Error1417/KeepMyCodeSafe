/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Temp coverstion cel to farh
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
    float degFah, // Degrees in Fahrenheit
          degCel; // Degrees in celceuis
    
    //Initialize or input i.e. set variable values
    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Celsius" << endl;
    cin >> degCel;
    
    //Map inputs -> outputs
    degFah = (degCel*9/5)+32;
    
    //Display the outputs
    cout << fixed << setprecision(1) << showpoint;
    cout << degCel << " Degrees Centigrade =" << setw(6) << degFah << " Degrees Fahrenheit";
    
    //Exit stage right or left!
    return 0;
}
