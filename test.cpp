#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<array>
#include<vector>
#include<stdio.h>
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
    double open;
    double close;
    int people;
public:
    building(string);
    building(string,int);
    building(string,int,double,double);
    ~building();
    void operator+(int x)
    {
        ++time[x];
    }
    double getopen()
    {
        return open;
    }
    double getclose()
    {
        return close;
    }
    void shownode()
    {
        cout<<"Shop name :"<<name<<endl<<"Max people:"<<people<<endl<<"Open time :"<<open<<endl<<"Close time:"<<close<<endl;
        for(int i=0;i<36;i++)
            cout<<time[i];
        cout<<endl;
    }
};
building::building(string nam,int peo,double ope,double clo)
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
        if(i>=op&&i<cl)
            time[i]=0;
        else
            time[i]=people;
    }
}
building::~building()
{
    cout<<name<<" has been close.\n";
}
void gettime(building b,double ope,double clo)
{
    double op=ope*2-8;
    if(op!=(int)op)
    {
        op++;
    }
    double cl=clo*2-8;
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
	int i,j,k,num,full,openmin,closemin,openhour,closehour;
	double open,close;
	string name;
	char choice;
	cin>>num;
	vector<building> LL;
	for(i=0;i<num;i++)
    {
        cout<<"Input name   *necessary: ";
        cin>>name;
        while(1)
        {
            cout<<"Do you want to input full people(Y/N)?\n";
            cin>>choice;
            if(choice=='Y'||choice=='y')
            {
                cout<<"Input full people: ";
                cin>>full;
                while(1)
                {
                    cout<<"Do you want to input open time and close time(Y/N)?\n";
                    cin>>choice;
                    if(choice=='Y'||choice=='y')
                    {
                        while(1)
                        {
                            cout<<"Input open time and close time.\n";
                            cout<<"Open time :";
                            scanf("%d.%d",&openhour,&openmin);
                            cout<<"Close time:";
                            scanf("%d.%d",&closehour,&closemin);
                            open=(double)openhour+(double)(openmin*0.01);
                            close=(double)closehour+(double)(closemin*0.01);
                            cout<<openhour<<" "<<openmin<<" "<<closehour<<" "<<closemin<<endl;//
                            cout<<open<<endl;//
                            cout<<close<<endl;//
                            if(open>22.00||open<4.00||close>22.00||close<4.00)
                            {
                                cout<<"Please add time between 4.00 to 22.00\n";
                            }
                            else if(openmin==0)
                            {
                                if(closemin==30)
                                {
                                    if(open>close)
                                    {
                                        cout<<"Cannot add open time more than close time.\n";
                                    }
                                    else
                                    {
                                        LL.push_back(building(name,full,open,close));
                                        break;
                                    }
                                }
                                else if(closemin==0)
                                {
                                    if(open>close)
                                    {
                                        cout<<"Cannot add open time more than close time.\n";
                                    }
                                    else
                                    {
                                        LL.push_back(building(name,full,open,close));
                                        break;
                                    }
                                }
                                else
                                {
                                    cout<<"No\n";
                                    cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                                }
                            }
                            else if(openmin==30)
                            {
                                if(closemin==30)
                                {
                                    if(open>close)
                                    {
                                        cout<<"Cannot add open time more than close time.\n";
                                    }
                                    else
                                    {
                                        LL.push_back(building(name,full,open,close));
                                        break;
                                    }
                                }
                                else if(closemin==0)
                                {
                                    if(open>close)
                                    {
                                        cout<<"Cannot add open time more than close time.\n";
                                    }
                                    else
                                    {
                                        LL.push_back(building(name,full,open,close));
                                        break;
                                    }
                                }
                                else
                                    cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                            }
                            else
                            {
                                cout<<"You must add open and close time X.00 or X.30\nTry again\n";


                            }
                        }
                        break;
                    }
                    else if(choice=='N'||choice=='n')
                    {
                        LL.push_back(building(name,full));
                        break;
                    }
                    else
                    {
                        cout<<"Try again!!\n";
                    }
                }
                break;
            }
            else if(choice=='N'||choice=='n')
            {
                LL.push_back(building(name));
                break;
            }
            else
            {
                cout<<"Try again!!\n";
            }
        }
    }
    for(i=0;i<num;i++)
    {
        LL[i].shownode();
    }
}