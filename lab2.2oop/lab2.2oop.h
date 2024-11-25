#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class MyTime
{
private:
    int hour, minute, second;
public:
    MyTime(int h, int m, int s) : hour(h), minute(m), second(s) {};
    std::string ToString() const;
    int ToSecSinceMidnight() const;
    MyTime TimeSinceMidnight(int t) const;
    MyTime AddOneSecond();
    MyTime AddOneMinute();
    MyTime AddOneHour();
    MyTime AddSeconds(int s);
    int Difference(const MyTime& mt1, const MyTime& mt2) const;
    std::string WhatLesson(const MyTime& mt) const;
};

#endif 
