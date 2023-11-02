/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
#include <ctime>
#include <fstream>
using namespace std;  //Libraries compiled under std


#include "CMovie.h"

CMovie::~CMovie(){
    //Clean Up the Dynamic Stuff
    delete [] movies->mveInfo;//Now the array of Structures
    delete movies;//Now deallocate the final Movie Structure
}

//Just copy, cut, and paste into a function.  Code already checked out in main.
void CMovie::display(){
    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        //I copied the output from Code-E then applied formatting
        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<movies->mveInfo[mvees].movName<<endl;
        cout<<setw(11)<<"Director:"<<movies->mveInfo[mvees].dirName<<endl;
        cout<<setw(11)<<"Year:"<<movies->mveInfo[mvees].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<movies->mveInfo[mvees].runTime<<endl;
    }
}

CMovie CMovie::operator=(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies;
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;            
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        movies->mveInfo[mvees].movName=obj.movies->mveInfo[mvees].movName;
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        movies->mveInfo[mvees].dirName=obj.movies->mveInfo[mvees].dirName;
        movies->mveInfo[mvees].yrRlsd=obj.movies->mveInfo[mvees].yrRlsd;
        movies->mveInfo[mvees].runTime=obj.movies->mveInfo[mvees].runTime;
    }   
    
    return *this;
}

CMovie::CMovie(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies;
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;            
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        movies->mveInfo[mvees].movName=obj.movies->mveInfo[mvees].movName;
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        movies->mveInfo[mvees].dirName=obj.movies->mveInfo[mvees].dirName;
        movies->mveInfo[mvees].yrRlsd=obj.movies->mveInfo[mvees].yrRlsd;
        movies->mveInfo[mvees].runTime=obj.movies->mveInfo[mvees].runTime;
    }    
}

//This implementation of this function was thoroughly tested out already
//in main.
CMovie::CMovie(){
    srand(static_cast<unsigned int>(time(0)));
    
    fstream binFile;
    binFile.open("data.bin",ios::in|ios::out|ios::binary);
    
    movies=new Movies;
    //Declare the Structure array
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    movies->nMovies = 100;
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];
    
    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){//Gotta frickin indent!!!!!
        MovieInfo *mveInfo = new MovieInfo;
        
        //I could generate 100 different movies,but I'm having problems with the binary file
        
        movies->mveInfo[mvees].movName = "Movie# " + to_string(mvees+1);
        movies->mveInfo[mvees].dirName = "Director# " + to_string(mvees+1);
        movies->mveInfo[mvees].yrRlsd = rand()% 25 + 1999;
        movies->mveInfo[mvees].runTime = rand()% 46+ 155;
        
        wrtBin(binFile,mveInfo);
        delete mveInfo;
    }
    
    int randRec=rand()%movies->nMovies;
    cout<<"Random record to find = "<<randRec<<endl;
    MovieInfo *mveInfo=readBin(binFile,randRec);
    prntTxt(mveInfo);
    cout<<"The size of the test structure = "<<sizeof(MovieInfo)<<" bytes"<<endl;
    delete mveInfo;
    binFile.close();
}

MovieInfo*readBin(fstream &in,int record){
    //Declare and initialize variables
    long cursor=0L;    //Where to place the cursor
    MovieInfo *a=new MovieInfo;//Declare the array to return
    
    //Find the record
    cursor=record*sizeof(MovieInfo);
    
    //Fill the structure
    in.seekg(cursor,ios::beg);
    in.read(reinterpret_cast<char *>(a),sizeof(MovieInfo));
    return a;
}

void CMovie::wrtBin(fstream &out,MovieInfo *a){
    out.write(reinterpret_cast<char *>(a),sizeof(MovieInfo));
}

void CMovie::prntTxt(MovieInfo *a){
    cout<<endl;
    cout<<"Structure Contents "<<endl;
    cout<<setw(6)<<a->movName<<endl;
    cout<<setw(6)<<a->dirName<<endl;
    cout<<setw(6)<<a->yrRlsd<<endl;
    cout<<setw(6)<<a->runTime<<endl;
    cout<<endl;
}