/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    const int NCARDS=52;//Number of Cards
    string face[]={"Ace","2","3","4","5",
                    "6","7","8","9",
                    "Ten","Jack","Queen","King"};   //Face Values of the Cards
    string suit[]={"Spades","Diamonds",
                   "Clubs","Hearts"};//All the suits in a deck
    fstream out;
    string fileName;
    
    //Initialize file parameters
    fileName="card.dat";
    out.open(fileName,ios::out);
    
    //Initialize Variables
    cout<<right;
    for(unsigned char card=0;card<NCARDS;card++){
        string strCard;
        strCard=face[card%13];
        strCard+="_";
        strCard+=suit[card/13];
        out <<setw(14)<<strCard<<endl;
        cout<<setw(14)<<strCard<<endl;
    }
    
    //Exit stage right!
    out.close();
    return 0;
}