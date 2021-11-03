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
#include "order.h"
#include "town.h"
#include "family.h"
#include "building.h"
building::building(string nam,int peo,double ope,double clo)
{
    name=nam;
    people=peo;
    open=ope;
    close=clo;
    int op=open*2-8;
    system("CLS");
    cout<<"Shop "<<name<<" register successful\n";
    if(open!=(int)open)
    {
        op++;
    }
    int cl=close*2-8;
    if(close!=(int)close)
    {
        cl++;
    }
    for(int i=0;i<36;i++)
    {
        if(i>=op&&i<cl)
            time[i]=0;
        else
            time[i]=people;
    }
    shownode();
}
building::building(string nam,int peo)
{
    system("CLS");
    name=nam;
    people=peo;
    open=6.00;
    close=18.00;
    int op=open*2-8;
    cout<<"Shop "<<name<<" register successful\n";
    if(open!=(int)open)
    {
        op++;
    }
    int cl=close*2-8;
    if(close!=(int)close)
    {
        cl++;
    }
    for(int i=0;i<36;i++)
    {
        if(i>=op&&i<cl)
            time[i]=0;
        else
            time[i]=people;
    }
    shownode();
}
building::building(string nam)
{
    system("CLS");
    name=nam;
    people=1;
    open=6.00;
    close=18.00;
    int op=open*2-8;
    cout<<"Shop "<<name<<" register successful\n";
    if(open!=(int)open)
    {
        op++;
    }
    int cl=close*2-8;
    if(close!=(int)close)
    {
        cl++;
    }
    for(int i=0;i<36;i++)
    {
        if(i>=op&&i<cl)
            time[i]=0;
        else
            time[i]=people;
    }
    shownode();
}
building::~building()
{
    //cout<<name<<" has been close.\n";
}
