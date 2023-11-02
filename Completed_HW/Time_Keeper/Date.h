/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: error
 *
 * Created on March 25, 2023, 2:15 PM
 */

#ifndef DATE_H
#define DATE_H

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date();
    Date(int year, int month, int day);
    int getYear();
    int getMonth();
    int getDay();
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void printDate();
};

#endif /* DATE_H */

