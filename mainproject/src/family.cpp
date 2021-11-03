#include "family.h"
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

family::family(string s){
            name=s;
            for(int i=0;i<36;i++){
                time[i]=0;
            }
            next=NULL;
}

family::~family(){
    // cout<<name<<" has been out.\n";
}

family* family::move_next(){
      return next;
}
void  family:: show_node(){
         cout<<"Family name:"<<name<<endl;
 }
void family::insert(family*& x){
     x->next=this;
}
void family::book(int i,int n){
		    //cout<<i<<"   "<<n<<endl;
            time[i]=n;
}
void family::display(){
		    cout<<"Family name:"<<name<<endl;
            for(int i=0;i<36;i++){
                cout<<time[i];
                if(i%2!=0)
                    cout<<" ";
            }
            cout<<endl;
}
