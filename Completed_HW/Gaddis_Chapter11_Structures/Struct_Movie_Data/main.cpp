/* 
 * Author: Ismael Perez
 * Created on October 3, 2022 
 * Purpose: Movie Data Structure (Gotten from the class recording)
 *       
 */

//System Level Libraries
#include <iostream>   
#include <cstdlib>    
#include <iomanip>    
using namespace std;  


const int SIZE=81; // size of directors name

struct MovieInfo{
    string movName;        //name of the movie
    char dirName[SIZE];    // directors name
    unsigned short yrRlsd; //year the movie was released
    unsigned short runTime;// run time of the movie
};

//Global Constants Only - Science/Math Related, Conversions, Array and Higher
//Dimensions.  Put Global Variables anywhere in your program i.e. variables

//Function Prototypes here, Function implementations after main!

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    const int NUM=10; // size of array
    MovieInfo mveInfo[NUM];//Static Array of structures
    int nMovies;// number of movies
    
   
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    cin>>nMovies;            
    

    for(int i=0; i<nMovies; i++){
        cin.ignore();         
        getline(cin,mveInfo[i].movName);
        cin.getline(mveInfo[i].dirName,SIZE-1);
        cin>>mveInfo[i].yrRlsd;
        cin>>mveInfo[i].runTime;

        //Mapping Process Inputs to Outputs

        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<mveInfo[i].movName<<endl;
        cout<<setw(11)<<"Director:"<<mveInfo[i].dirName<<endl;
        cout<<setw(11)<<"Year:"<<mveInfo[i].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<mveInfo[i].runTime<<endl;
    }
    
    //Exit stage right!
    return 0;
}