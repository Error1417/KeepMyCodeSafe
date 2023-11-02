/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: error
 *
 * Created on March 25, 2023, 2:16 PM
 */

#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hour;
    int minute;
    int second;
public:
    Time();
    Time(int hour, int minute, int second);
    int getHour();
    int getMinute();
    int getSecond();
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    void printTime();
};

#endif /* TIME_H */

