/* 
 * File:   main.cpp
 * Author: Ismael Perez
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  population
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
const int PERCENT = 100;
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) 
{
    //Set the random number seed
    
    //Declare Variables
    int pop, //Population
       dys; // Number of days
    float perPop, // Percentage of population increase
          holder=0,
          popPrDy = 0; // Population per day
    
    //Initialize or input i.e. set variable values
    cout << "Population Predictor" << endl;
    cout << "Enter a starting population size(*Number higher than 2)" << endl;
    cin >> pop;
    cout << "Enter number of days population will multiply(*Number higher than 1)" << endl;
    cin >> dys;
    cout << "Enter percent of population increase per day(*15,15.6,4.6) Percent" << endl;
    cin >> perPop;
    //Map inputs -> outputs
    
    if(pop < 2 || perPop < 0|| dys < 1){
        cout << "Invalid Input, TRY AGAIN" << endl;
        return 0;
    }
    
    for(int i = 0; i <= dys; i++){
        holder = pop*(perPop / PERCENT)+holder;
        popPrDy = holder + pop;
        cout << setprecision(2) << showpoint << fixed;
        cout << "Day " << i+1 << " = Population of " << popPrDy << endl;
    }
  

    //Display the output
    
    //Exit stage right or left!
    return 0;
}
