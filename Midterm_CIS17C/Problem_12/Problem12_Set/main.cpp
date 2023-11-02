/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 */

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>
#include <vector>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(int *);
void swap(int *,int *);
void minPos(int *,int,int);
void mrkSort(int *,int);
int *mode(const int *,int);
int *copy(const int *,int);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=15;
    int modNum=10;
    int *ary=fillAry(arySize,modNum);
    
    //Print the initial array
    prntAry(ary,arySize,10);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the modal information of the array
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

int *mode(const int *array, int arySize) {
    // Use a set to store the unique numbers in the array
    set<int> uniqueNums;

    // Populate the set with the array's elements
    for (int i = 0; i < arySize; i++) {
        uniqueNums.insert(array[i]);
    }

    // Variables to store frequency details
    int maxFreq = 0;
    vector<int> modes;

    // Loop through the set to determine mode frequency
    for (int num : uniqueNums) {
        int count = 0;

        // Check the frequency of each unique number in the array
        for (int i = 0; i < arySize; i++) {
            if (array[i] == num) {
                count++;
            }
        }

        // Update the mode(s) based on the frequency
        if (count > maxFreq) {
            maxFreq = count;
            modes.clear();
            modes.push_back(num);
        } else if (count == maxFreq) {
            modes.push_back(num);
        }
    }

    // Allocate memory for the mode array and set its values
    int *modeAry = new int[modes.size() + 2];
    modeAry[0] = modes.size();
    modeAry[1] = maxFreq;

    for (int i = 0; i < modes.size(); i++) {
        modeAry[i + 2] = modes[i];
    }

    return modeAry;
}

void prntMod(int *ary){
    cout<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}