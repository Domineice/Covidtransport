#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>

class NODE{
protected:
      int data;
      NODE* next;
public:
        NODE(int);
        void show_node();
        void insert(NODE*&);
        NODE* move_next();
        ~NODE();
};

NODE::NODE(int x){
      data=x;
      next=NULL;
      cout<<"adding "<< x<<endl;
}
NODE:: ~NODE(){
      cout<<"Node "<<data<<" is being deleted"<<endl;
}
NODE* NODE::move_next(){
      return next;
}
void  NODE:: show_node(){
         cout<<"Node data:"<<data<<endl;
 }
void NODE::insert(NODE*& x){
     x->next=this;

     }

class  family:public NODE{
	private:
		int time[];
		string name;
		int position;
		family * next;
	public:
		family(string,int,int);
		~family();
		int get_position();
		void addtime(int x,int time);
};

family::family(string s ,int i ,int j):NODE(j){

}

class town{
	private:
		int size;
		NODE*head;
	public:
		void add_family(NODE*&);
		void show_all();
		town();
		~town();
};

town::town(){
	size=0;
	head=NULL;
}

town::~town(){
	int i;
	NODE *t;
	for(i=0;i<size;i++){
            t=head;
             head=t->move_next();
             delete(t);
         }
}

void town::show_all(){
     NODE* t=head;
     int i;
     for(i=0;i<size;i++){
         t->show_node();
         t=t->move_next();
     }
}

void town::add_family(NODE *&A){

          head->insert(A);
          head=A;

       size++;

 }

class building{
private:
    int time[36];
    string name;
    float open;
    float close;
    int people;
public:
    building(string);
    building(string,int);
    building(string,int,float,float);
    ~building();
    void operator+(int x)
    {
        ++time[x];
    }
    float getopen()
    {
        return open;
    }
    float getclose()
    {
        return close;
    }
};
building::building(string nam,int peo,float ope,float clo)
{
    name=nam;
    people=peo;
    open=ope;
    close=clo;
    int op=open*2-8;
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
        if(i>=op&&i<=cl)
            time[i]=0;
        else
            time[i]=people;
    }
}
building::building(string nam,int peo)
{
    name=nam;
    people=peo;
    open=6.00;
    close=18.00;
    int op=open*2-8;
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
        if(i>=op&&i<=cl)
            time[i]=0;
        else
            time[i]=people;
    }
}
building::building(string nam)
{
    name=nam;
    people=1;
    open=6.00;
    close=18.00;
    int op=open*2-8;
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
        if(i>=op&&i<=cl)
            time[i]=0;
        else
            time[i]=people;
    }
}
building::~building()
{
    cout<<name<<" has been close.\n";
}
void gettime(building b,float ope,float clo)
{
    float op=ope*2-8;
    if(op!=(int)op)
    {
        op++;
    }
    float cl=clo*2-8;
    if(cl!=(int)cl)
    {
        cl++;
    }
    for(int i=op;i<cl;i++)
    {
        b+i;
    }
}
int main(){
	town A;
	NODE* t;
	t= new family("Helo",123123,1);
	A.add_family(t);
	t= new family("HAHA",231,2);
	A.add_family(t);
	A.show_all();

}
