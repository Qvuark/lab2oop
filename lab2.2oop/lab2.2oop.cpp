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
std::string MyTime::WhatLesson(const MyTime& mt) const
{
    int time = mt.ToSecSinceMidnight();
    if (time >= 28800 && time <= 33600)
        return "Зараз перша пара";
    if (time >= 33601 && time <= 34800)
        return "Зараз перерва між першою та другою парою";
    if (time >= 34801 && time <= 39600)
        return "Зараз друга пара";
    if (time >= 39601 && time <= 40800)
        return "Зараз перерва між другою та третьою парою";
    if (time >= 40801 && time <= 45600)
        return "Зараз третя пара";
    if (time >= 45601 && time <= 46800)
        return "Зараз перерва між третьою та четвертою парою";
    if (time >= 46801 && time <= 51600)
        return "Зараз четверта пара";
    if (time >= 51601 && time <= 52800)
        return "Зараз перерва між четвертою та пятою парою";
    if (time >= 52801 && time <= 57600)
        return "Зараз п'ята пара";
    if (time >= 57601 && time <= 58800)
        return "Зараз перерва між п'ятою та шостою парою";
    if (time >= 58801 && time <= 63600)
        return "Зараз шоста пара";
    else
        return "Пар немає, ти вільна людина (поки що)";
}