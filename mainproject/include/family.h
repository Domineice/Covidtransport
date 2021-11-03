#ifndef FAMILY_H
#define FAMILY_H
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


class  family{
		int time[36];
		string name;
		family* next;
	public:
		family(string);
		void book(int,int);
		void display();
		string getname(){
            return name;
		}
		int gettime(int i){
            return time[i];
		}
		void show_node();
        void insert(family*&);
        family* move_next();
		~family();
};

#endif // FAMILY_H
