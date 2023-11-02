/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Temp coverstion
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
float celsius(float);
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) 
{
    //Set the random number seed
    
    //Declare Variables
    float degFah = 0, // Degrees in Fahrenheit
          degCel = 0 ; // Degrees in celceuis
    
    //Initialize or input i.e. set variable values
    cout << "Temperature Converter" << endl;
    
    //Map inputs -> outputs
    for(int i = 0; i <= 20; i++){
        degFah = i;
        degCel = celsius(degFah);
        
        cout << fixed << setprecision(2) << showpoint;
        cout << degFah << " Degrees Fahrenheit = " << setw(6) << degCel << " Degrees Centigrade" << endl;
    }
    
    //Display the outputs
    
    //Exit stage right or left!
    return 0;
}

float celsius(float f) {
    return (f - 32) * 5/9;
}