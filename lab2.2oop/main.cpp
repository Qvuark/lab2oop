#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "lab2.2oop.h"

int main() 
{
    setlocale(LC_ALL, "ukr");
    std::cout<<"\nEnter your time: ";
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> t(3);
    iss>>t[0]>>t[1]>>t[2];
    MyTime time(t[0],t[1],t[2]);
    std::cout<<"Current Time: "<<time.ToString()<<std::endl;
    bool exit = false;
    while (!exit) 
    {
        std::cout<<R"(Choose an option:
1. Add one second
2. Add one minute
3. Add one hour
4. Add seconds
5. Calculate difference between two times
6. Check what lesson is now
7. Exit
Enter your choice: )";
        int choice;
        std::cin>>choice;
        switch (choice) 
        {
        case 1:
        {
            time = time.AddOneSecond();
            std::cout << "Time after adding one second: " << time.ToString() << std::endl;
            break;
        }
        case 2:
        {
            time = time.AddOneMinute();
            std::cout << "Time after adding one minute: " << time.ToString() << std::endl;
            break;
        }
        case 3:
        {
            time = time.AddOneHour();
            std::cout << "Time after adding one hour: " << time.ToString() << std::endl;
            break;
        }
        case 4:
        {
            std::cout<<"Enter seconds to add: ";
            int seconds;
            std::cin>>seconds;
            time = time.AddSeconds(seconds);
            std::cout <<"Time after adding "<<seconds<<" seconds: "<<time.ToString()<<std::endl;
            break;
        }
        case 5:
        {
            std::getline(std::cin, input);
            std::istringstream iss1(input);
            std::vector<int> time1Entered(3);
            iss1 >> time1Entered[0] >> time1Entered[1] >> time1Entered[2];
            MyTime time1(time1Entered[0], time1Entered[1], time1Entered[2]);
            std::cout << "Enter another time with which you want to know the difference: ";
            std::getline(std::cin, input);
            std::istringstream iss2(input);
            std::vector<int> time2Entered(3);
            iss2 >> time2Entered[0] >> time2Entered[1] >> time2Entered[2];
            MyTime time2(time2Entered[0], time2Entered[1], time2Entered[2]);
            int difference = time.Difference(time1, time2);
            std::cout << "Difference between the two times in seconds" << difference<< std::endl;
            break;
        }
        case 6:
            std::cout << time.WhatLesson(time) << std::endl;
            break;
        case 7:
            exit = true;
            break;
        default:
            throw std::invalid_argument("Invalid choice. Please enter a number between 1 and 7.");
            break;
        }
    }
}