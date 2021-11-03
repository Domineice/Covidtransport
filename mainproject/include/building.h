#ifndef BUILDING_H
#define BUILDING_H
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

class building{
private:
    int time[36];
    string name;
    double open;
    double close;
    int people;
    vector<order> orderlist;
    vector<int> gotoshop;
public:
    building(string);
    building(string,int);
    building(string,int,double,double);
    ~building();
    void addorder(string nam,double in,double out)
    {
        orderlist.push_back(order(nam,in,out));
        for(unsigned int i=0;i<orderlist.size();i++)
        {
            for(unsigned int j=i+1;j<orderlist.size();j++)
            {
                if(orderlist[i].returnin()>orderlist[j].returnin())
                {
                    swap(orderlist[i],orderlist[j]);
                }
            }
        }
    }
    void showorder()
    {
        for(unsigned int i=0;i<orderlist.size();i++)
        {
            cout<<"     "<<i+1<<") ";
            orderlist[i].shownode();
        }
    }
    int getnumpeople()
    {
        return gotoshop.size();
    }
    void checkadd(int x)
    {
        for(unsigned int i=0;i<gotoshop.size();i++)
        {
            if(gotoshop[i]==x)
            {
                return;
            }
        }
        gotoshop.push_back(x);
        return;
    }
    void operator+(int x)
    {
        ++time[x];
    }
    int getpeople()
    {
        return people;
    }
    double getopen()
    {
        return open;
    }
    double getclose()
    {
        return close;
    }
    int gettime(int x)
    {
        return time[x];
    }
    void shownode()
    {
        cout<<"Shop name :"<<name<<endl<<"Max people:"<<people<<endl<<"Open time :"<<open<<endl<<"Close time:"<<close<<endl;
      /*  for(int i=0;i<36;i++)
        {
            cout<<time[i];
            if(i%2!=0)
                cout<<" ";
        }
        cout<<endl;*/
        cout<<endl<<"======================================================================\n";

    }
    void showtime()
    {
          for(int i=0;i<36;i++)
        {
            cout<<time[i];
            if(i%2!=0)
                cout<<" ";
        }

        cout<<endl;
    }
    string getname(){
    	return name;
	}
};
#endif // BUILDING_H
