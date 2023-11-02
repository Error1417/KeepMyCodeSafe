/* 
 * File:   
 * Author: Ismael Perez 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
struct Divison{
    float firQurSa, // first quarter sales
          secQurSa, // second quarter sales
          thrQurSa, // third quarter sales 
          furQurSa, // fourth quarter sales
          totAnSa, // total annual sales
          avrQurSa; // average quarter sales
};

//Function Prototypes
void prompt(Divison); // prompt the User

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Divison division;
    //Initialize Variables
    cout << "North" << endl;
    prompt(division);
    cout << endl;
    
    cout << "West" << endl;
    prompt(division);
    cout << endl;
    
    cout << "East" << endl;
    prompt(division);
    cout << endl;
    
    cout << "South" << endl;
    prompt(division);
    //Process or map Inputs to Outputs
    
    //Display Outputs

    //Exit stage right!
    return 0;
}

void prompt(Divison d){
    cout << setprecision(2) << showpoint << fixed;
    
    cout << "Enter first-quarter sales:" << endl;
    cin >> d.firQurSa;
    cout << "Enter second-quarter sales:" << endl;
    cin >> d.secQurSa;
    cout << "Enter third-quarter sales:" << endl;
    cin >> d.thrQurSa;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> d.furQurSa;
    
    d.totAnSa = d.firQurSa + d.secQurSa + d.thrQurSa + d.furQurSa;
    
    cout << "Total Annual sales:$" << d.totAnSa << endl;
    
    d.avrQurSa = d.totAnSa/4;
    
    cout << "Average Quarterly Sales:$" << d.avrQurSa;
}

