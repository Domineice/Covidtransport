#ifndef ORDER_H
#define ORDER_H
#pragma once
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<array>
#include<vector>
#include<stdio.h>
#include <iomanip>


class order
{
private:
    string famname;
    double timein;
    double timeout;
public:
    order(string name,double in,double out)
    {
        famname=name;
        timein=in;
        timeout=out;
    }
    void shownode()
    {
        //cout<<fixed();
        cout <<setprecision(2)<<fixed;
        cout<<famname<<" family go to shop between "<<timein<<" and "<<timeout<<endl;
    }
    double returnin()
    {
        return timein;
    }
};
#endif // ORDER_H
