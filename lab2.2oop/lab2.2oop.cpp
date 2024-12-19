#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "lab2.2oop.h"

std::string MyTime::ToString() const
{
    std::ostringstream oss;
    oss << hour << ":" << minute << ":" << second;
    return oss.str();
}
int MyTime::ToSecSinceMidnight() const
{
    return hour * 3600 + minute * 60 + second;
}
MyTime MyTime::TimeSinceMidnight(int t) const
{
    int secPerDay = 60 * 60 * 24;
    t %= secPerDay;
    if (t < 0)
        t += secPerDay;
    int h = t / 3600;
    int m = (t / 60) % 60;
    int s = t % 60;
    return MyTime(h, m, s);
}
MyTime MyTime::AddOneSecond()
{
    int totalSeconds = ToSecSinceMidnight() + 1;
    return TimeSinceMidnight(totalSeconds);
}
MyTime MyTime::AddOneMinute()
{
    int totalSeconds = ToSecSinceMidnight() + 60;
    return TimeSinceMidnight(totalSeconds);
}
MyTime MyTime::AddOneHour()
{
    int totalSeconds = ToSecSinceMidnight() + 3600;
    return TimeSinceMidnight(totalSeconds);
}
MyTime MyTime::AddSeconds(int s)
{
    int totalSeconds = ToSecSinceMidnight() + s;
    return TimeSinceMidnight(totalSeconds);
}
int MyTime::Difference(const MyTime& mt1, const MyTime& mt2) const
{
    int diffSeconds = mt1.ToSecSinceMidnight() - mt2.ToSecSinceMidnight();
    return diffSeconds;
}
std::string MyTime::WhatLesson() const 
{
    int time = ToSecSinceMidnight();
    int startLessons = 8 * 60 * 60;         // 8:00 в секундах
    int endLessons = (17 * 60 + 40) * 60;  // 17:40 в секундах
    int lessonTime = 80 * 60;              // 1 пара = 80 минут в секундах
    int breakTime = 20 * 60;               // Перерыв = 20 минут в секундах

    if (time < startLessons) 
    {
        return "Пари ще не розпочалися";
    }
    else if (time >= endLessons) 
    {
        return "Пари вже закінчилися";
    }
    else 
    {
        for (int i = 0; i < 6; i++) 
        {
            int lessonStart = startLessons + (lessonTime + breakTime) * i;
            int lessonEnd = lessonStart + lessonTime;
            int breakStart = lessonEnd + 1;
            int breakEnd = breakStart + breakTime;

            if (time >= lessonStart && time <= lessonEnd) 
            {
                return "Зараз " + std::to_string(i + 1) + "-а пара";
            }
            else if (time >= breakStart && time < breakEnd) 
            {
                return "Зараз перерва між " + std::to_string(i + 1) + "-ю та " + std::to_string(i + 2) + "-ю парою";
            }
        }
    }

    return "Невідомо";
}