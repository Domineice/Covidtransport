#ifndef TOWN_H
#define TOWN_H
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
#include "family.h"


class town{
	private:
		int size;
		family*head;
	public:
		void add_family(family*&);
		void show_all();
		family* find_fam(string);
		int getsize(){
            return size;
		}
		town();
		~town();
};

#endif // TOWN_H
