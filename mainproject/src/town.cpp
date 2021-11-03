#include "town.h"
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


town::town(){
	size=0;
	head=NULL;
}

town::~town(){
	int i;
	family *t;
	for(i=0;i<size;i++){
            t=head;
             head=t->move_next();
             delete(t);
         }
}

family* town::find_fam(string s){
        int i;
        int check=0;
        family* t=head;
        for(i=0;i<size;i++){
            if(s.compare(t->getname())==0){
                check=1;
                return t;
            }
            t=t->move_next();
        }
        if(check==0){
            return NULL;
        }
}

void town::show_all(){
     family* t=head;
     int i;
     for(i=0;i<size;i++){
         t->show_node();
         t=t->move_next();
     }
}

void town::add_family(family *&A){

          head->insert(A);
          head=A;

       size++;

 }
