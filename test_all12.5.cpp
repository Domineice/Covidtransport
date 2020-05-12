#include <conio.h>
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<array>
#include<vector>
#include<stdio.h>


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

        cout<<"     "<<famname<<" family go to shop between "<<timein<<" and "<<timeout<<endl;
    }
    double returnin()
    {
        return timein;
    }
};
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
      //cout<<"adding "<< x<<endl;
}
NODE:: ~NODE(){
      //cout<<"Node "<<data<<" is being deleted"<<endl;
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

class  family{
		int time[36];
		string name;
	public:
		family(string);
		book(int i,int n){
		    //cout<<i<<"   "<<n<<endl;
            time[i]=n;
		}
		void display(){
		    cout<<"Family name:"<<name<<endl;
            for(int i=0;i<36;i++){
                cout<<time[i];
                if(i%2!=0)
                    cout<<" ";
            }
            cout<<endl;
		}
		string getname(){
            return name;
		}
		int gettime(int i){
            return time[i];
		}
		~family();
};

family::family(string s){
            name=s;
            for(int i=0;i<36;i++){
                time[i]=0;
            }
}

family::~family(){
    // cout<<name<<" has been out.\n";
}

class town{
	private:
		int size;
		NODE*head;
	public:
		void add_family(NODE*&);
		void show_all();
		NODE* get_node(){
		    NODE*t=head;
            return t;
		}
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
        for(int i=0;i<orderlist.size();i++)
        {
            for(int j=i+1;j<orderlist.size();j++)
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
        for(int i=0;i<orderlist.size();i++)
        {
            orderlist[i].shownode();
        }
    }
    int getnumpeople()
    {
        return gotoshop.size();
    }
    void checkadd(int x)
    {
        for(int i=0;i<gotoshop.size();i++)
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
        if(i>=op&&i<cl)
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
        if(i>=op&&i<cl)
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
    //cout<<name<<" has been close.\n";
}
int gettime(double ope)
{
    int op=ope*2-8;
    if(op!=(int)op)
    {
        op++;
    }
    return op;
}
void printbuild(building bb)
{
    cout<<"Amount of people by time\n";
    int i,tim;
    for(i=0,tim=4;i<36;i++,tim++)
    {
        if(i>=gettime(bb.getopen())&&i<gettime(bb.getclose()))
        {
            cout<<"     "<<tim<<".00 to "<<tim<<".30 has "<<bb.gettime(i)<<" family\n";
        }
        i++;
        if(i>=gettime(bb.getopen())&&i<gettime(bb.getclose()))
        {
            cout<<"     "<<tim<<".30 to "<<tim+1<<".00 has "<<bb.gettime(i)<<" people\n";
        }
    }
}
int main(){
	int i,j,k,num,full,openmin,closemin,openhour,closehour;
	double open,close;
	string name;
	string choice;
	string fam_name;
	family* temp;
	int n=0;
	string more_st,more_fam;
	string res;
	int ent_h,ent_mn,out_h,out_mn,thick;
	double ent,out;
	int check,entt,outt;
	int t;
	cout<<"How many of the first group of shop?\n     ";
	if(!(cin>>num))
    {
        cout<<"Invalid input\n";
        return 0;
    }
	if(num==0)
    {
        cout<<"No shop open.\n";
        return 0;
    }
    int oo=0;
	vector<building> LL;
	vector<family> T;
	for(i=0;i<num;i++)
    {
        cout<<"Input name   *necessary\n     ";
        cin>>name;
        for(i=0;i<LL.size();i++)
        {
            if(name.compare(LL[i].getname())==0)
            {
                cout<<"This shop has already register\n";
                oo=1;
                break;
            }
        }
        if(oo==1)
        {
            oo=0;
            continue;
        }
        while(1)
        {
            cout<<"Do you want to input full people(Y/N)?\n     ";
            cin>>choice;
            if(choice=="Y"||choice=="y")
            {
                try
                {
                cout<<"Input full people: ";
                if(!(cin>>full))
                    throw 1;
                while(1)
                {
                    cout<<"Do you want to input open time and close time(Y/N)?\n     ";
                    cin>>choice;
                    if(choice=="Y"||choice=="y")
                    {
                        while(1)
                        {
                            try
                            {
                               cout<<"Input open time and close time.\n";
                                cout<<"Open time :";
                                if(!scanf("%d.%d",&openhour,&openmin))
                                    throw 1;
                                cout<<"Close time:";
                                if(!scanf("%d.%d",&closehour,&closemin))
                                throw 1;
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
                            catch (int err)
                            {
                                if(err==1)
                                    cout<<"Invalid input\n";
                                cin.clear();
                                cin.ignore(5000,'\n');
                            }
                        }
                        break;
                    }
                    else if(choice=="N"||choice=="n")
                    {
                        LL.push_back(building(name,full));
                        break;
                    }
                    else
                    {
                        cout<<"Try again!!\n";
                        cin.clear();
                                cin.ignore(5000,'\n');
                    }
                }
                break;
                }
                catch(int err)
                {
                                if(err==1)
                                    cout<<"Invalid input\n";
                                cin.clear();
                                cin.ignore(5000,'\n');
                            }
            }
            else if(choice=="N"||choice=="n")
            {
                LL.push_back(building(name));
                break;
            }
            else
            {
                cout<<"Try again!!\n";
                cin.clear();
                cin.ignore(5000,'\n');
            }
        }
    }
    /*for(i=0;i<num;i++)
    {
        LL[i].shownode();
    }*/
    int oper=0,oper2=0,numshop,faminint,famoutint;
    double famin,famout;
    string returntime,press2,press;
    string shopname,famname;
    while(1)
    {
        cout<<"Next function?\n     Press 1 for add shop\n     Press 2 for add time to shop\n     Press 3 for show shop time\n     Press 4 for show family time\n     Press 5 for exit\n     Press :";
        cin>>press;
        if(press=="1")
        {
            cin.clear();
            cin.ignore(5000,'\n');
            cout<<"Input name   *necessary: ";
            cin>>name;
            for(i=0;i<LL.size();i++)
            {
                if(name.compare(LL[i].getname())==0)
                {
                    cout<<"This shop has already register\n";
                    oo=1;
                    break;
                }
            }
            if(oo==1)
            {
                oo=0;
                continue;
            }
            while(1)
            {
                cout<<"Do you want to input full people(Y/N)?\n     ";
                cin>>choice;
                if(choice=="Y"||choice=="y")
                {
                    try
                    {
                    cout<<"Input full people: ";
                    if(!(cin>>full))
                        throw 1;
                    while(1)
                    {
                        cout<<"Do you want to input open time and close time(Y/N)?\n     ";
                        cin>>choice;
                        if(choice=="Y"||choice=="y")
                        {
                            while(1)
                            {
                                try
                                {
                                    cout<<"Input open time and close time.\n";
                                    cout<<"Open time :";
                                    if(!scanf("%d.%d",&openhour,&openmin))
                                        throw 1;
                                    cout<<"Close time:";
                                    if(!scanf("%d.%d",&closehour,&closemin))
                                        throw 1;
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
                                                cout<<name<<" shop has been register successful\n";
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
                                                cout<<name<<" shop has been register successful\n";
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
                                                cout<<name<<" shop has been register\n";
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
                                catch (int err)
                                {
                                     if(err==1)
                                        cout<<"Invalid input\n";
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                }
                            }
                            break;
                        }
                        else if(choice=="N"||choice=="n")
                        {
                            LL.push_back(building(name,full));
                            break;
                        }
                        else
                        {
                            cout<<"Try again!!\n";
                            cin.clear();
                            cin.ignore(5000,'\n');
                        }
                    }
                    break;
                }
                catch(int err)
                {
                    if(err==1)
                        cout<<"Invalid input\n";
                    cin.clear();
                    cin.ignore(5000,'\n');
                    }
                }
                else if(choice=="N"||choice=="n")
                {
                    LL.push_back(building(name));
                    break;
                }
                else
                {
                    cout<<"Try again!!\n";
                    cin.clear();
                    cin.ignore(5000,'\n');
                }
            }
       /* for(i=0;i<LL.size();i++)
        {
            LL[i].shownode();
        }*/
        }
        else if(press=="2")
        {
            cin.clear();
            cin.ignore(5000,'\n');
        while(1){
            check=0;
            cout<<"Input your family name: ";
            cin>>fam_name;
            if(n!=0){
                for(i=0;i<n;i++){
                    if(fam_name.compare(T[i].getname())==0){
                        check=1;
                        t=i;
                        //cout<<"Check "<<check<<" t="<<t<<endl;
                        break;
                    }
                }
            }
            if(check==0){
                temp = new family(fam_name);
                T.push_back(*temp);
                t=n;
                //cout<<"Check "<<check<<" t="<<t<<endl;
            }
            //T[t].display();
            while(1)
            {
                cout<<"Please select the store: ";
                cin>>res;
                try
                {
                    oper=0;
                    for(i=0;i<LL.size();i++)
                    {
                        if(res.compare(LL[i].getname())==0)
                            oper=1;
                    }
                    if(oper==0)
                        throw res;
                    while(1)
                    {
                        try
                        {
                            cout<<"Input time when you will enter: ";
                            ent_h=100;
                            ent_mn=100;
                            out_h=100;
                            out_mn=100;
                            if(!scanf("%d.%d",&ent_h,&ent_mn))
                            {
                                throw 1;
                            }
                            if(ent_h>24||ent_h<0||ent_mn<0||ent_mn>=60)
                                throw 1;
                            if(ent_h>22||ent_h<4||ent_mn<0||ent_mn>=60)
                                throw 2;
                            if(ent_h==22&&ent_mn!=0)
                                throw 2;
                            if(ent_mn!=30&&ent_mn!=0)
                                throw 4;
                            cout<<"Input time when you will leave: ";
                            if(!scanf("%d.%d",&out_h,&out_mn))
                            {
                                throw 1;
                            }
                            if(out_h>24||out_h<0||out_mn<0||out_mn>=60)
                                throw 1;
                            if(out_h>22||out_h<4||out_mn<0||out_mn>=60)
                                throw 2;
                            if(out_h==22&&out_mn!=0)
                                throw 2;
                            if(out_mn!=30&&out_mn!=0)
                                throw 4;
                            if((out_h*60)+out_mn<=(ent_h*60)+ent_mn)
                                throw 3;
                            ent = (double)ent_h+(double)(ent_mn*0.01);
                            out = (double)out_h+(double)(out_mn*0.01);
                            entt=ent*2-8;
                            if(ent!=(int)ent)
                                entt++;
                            outt=out*2-8;
                            if(out!=(int)out)
                                outt++;
                            for(i=entt;i<outt;i++){
                                if(T[t].gettime(i)!=0){
                                    throw 5;
                                    break;
                                }
                            }
                            for(i=0;i<LL.size();i++)
                            {
                                if (res.compare(LL[i].getname())==0)
                                {
                                    for(int j=entt;j<outt;j++)
                                    {
                                        if(LL[i].gettime(j)>=LL[i].getpeople())
                                            throw 0;
                                    }
                                    for(int j=entt;j<outt;j++)
                                    {
                                        LL[i]+j;
                                        T[t].book(j,i+1);

                                    }
                                    LL[i].checkadd(t);
                                    //T[t].display();
                                    LL[i].addorder(fam_name,ent,out);
                                    cout<<"Your register has been successful\n";
                                    //LL[i].shownode();
                                }
                            }
                            break;
                        }
                        catch(int err)
                        {
                            if(err==0)
                            {
                                cout<<"This time are full\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                cin>>returntime;
                                if(returntime=="F"||returntime=="f")
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    break;
                                }
                                cin.clear();
                                    cin.ignore(5000,'\n');
                            }
                            else if(err==1)
                            {
                                cout<<"Invalid input\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                cin>>returntime;
                                if(returntime=="F"||returntime=="f")
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    break;
                                }
                                cin.clear();
                                    cin.ignore(5000,'\n');
                            }
                            else if(err==2)
                            {
                                cout<<"This time you must stay home\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                cin>>returntime;
                                if(returntime=="F"||returntime=="f")
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    break;
                                }
                                cin.clear();
                                cin.ignore(5000,'\n');
                            }
                            else if(err==3)
                            {
                                cout<<"Cannot add open time more than close time\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                cin>>returntime;
                                if(returntime=="F"||returntime=="f")
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    break;
                                }
                                cin.clear();
                                cin.ignore(5000,'\n');
                            }
                            else if(err==4)
                            {
                                cout<<"You must add open and close time X.00 or X.30\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                cin>>returntime;
                                if(returntime=="F"||returntime=="f")
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    break;
                                }
                                cin.clear();
                                cin.ignore(5000,'\n');
                            }
                            else if(err==5)
                            {
                                cout<<"You have already reserved this time\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                cin>>returntime;
                                if(returntime=="F"||returntime=="f")
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    break;
                                }
                                cin.clear();
                                cin.ignore(5000,'\n');
                            }
                            cin.clear();
                            cin.ignore(5000,'\n');
                        }
                    }
                    try
                    {
                        while(1)
                        {
                            cout<<"Do you want to reserve more(Y/N)?\n     ";
                            cin>>more_st;
                            if(more_st=="N"||more_st=="n")
                                throw 1;
                            else if(more_st=="Y"||more_st=="y")
                                throw 2;
                            else
                            {
                                cout<<"Try again!!\n";
                                cin.clear();
                                cin.ignore(5000,'\n');
                            }
                        }
                    }
                    catch(int err)
                    {
                        if(err==1)
                            break;
                    }
                }
                catch(string err)
                {
                        cout<<"Cannot find "<<err<<" shop.\n";
                        cout<<"Press F for cancel, any key for add shop again\n     ";
                        cin>>returntime;
                        if(returntime=="F"||returntime=="f")
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            break;
                        }
                        cin.clear();
                        cin.ignore(5000,'\n');
                }
            }
            try
            {
                while(1)
                {
                    cout<<"Do other families want to reserve(Y/N)?\n     ";
                    cin>>more_fam;
                    if(more_fam=="N"||more_fam=="n")
                        throw 1;
                    else if(more_fam=="Y"||more_fam=="y")
                        throw 2;
                    else
                    {
                        cout<<"Try again!!\n";
                        cin.clear();
                        cin.ignore(5000,'\n');
                    }
                }
            }
            catch(int err)
            {
                if(err==1){
                    if(check==0)n++;
                    break;
                }
            }
            /*cout<<"In loop"<<endl;
            if(check==0)n++;
                cout<<n<<endl;
            for(i=0;i<n;i++)
            {
                T[i].display();
            }*/
        }
    }
        else if(press=="3")
        {
            cin.clear();
            cin.ignore(5000,'\n');
            try
            {
                while(1)
                {
                    cout<<"What shop do you want to see?\n     ";
                    cin>>shopname;
                    check=0;
                    for(int i=0;i<LL.size();i++)
                    {
                        if(shopname.compare(LL[i].getname())==0)
                        {
                            check=1;
                            t=i;
                            break;
                        }
                    }
                    if(check==1)
                    {
                        cout<<"Order list time\n";
                        LL[t].showorder();
                        printbuild(LL[t]);
                    }
                    else if(check==0)
                    {
                        cout<<"This shop cannot be found\n";


                    }
                    cout<<"Press F for check other shop \nPress any key for return to main menu\n     ";
                        cin>>press2;
                        if(press2=="F"||press2=="f")
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            continue;
                        }
                        else
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            break;
                        }
                }
            }
            catch(int err)
            {

            }
        }
        else if(press=="4")
        {
            cin.clear();
            cin.ignore(5000,'\n');
            while(1)
            {
                cout<<"What family do you want to see?\n";
            cin>>famname;
            check=0;
            for(int i=0;i<T.size();i++)
            {
                if(famname.compare(T[i].getname())==0)
                {
                    check=1;
                    t=i;
                    break;
                }
            }
                    if(check==1)
                    {
                        cout<<"Order list time of "<<famname<<" family\n";
                        numshop=0;
                        for(int j=0;j<36;)
                        {
                            if(T[t].gettime(j)!=0)
                            {

                                numshop=T[t].gettime(j);
                                faminint=j;
                                while(T[t].gettime(j)==numshop)
                                {
                                    j++;
                                }
                                famout=(j+8)/2;
                                if(j%2!=0)
                                    famout+=0.3;
                                famin=(faminint+8)/2;
                                if(faminint%2!=0)
                                    famin+=0.3;
                                cout<<"     "<<famin<<" to "<<famout<<" go to "<<LL[numshop-1].getname()<<" shop\n";
                                j--;
                            }
                            j++;
                        }
                    }
                    else if(check==0)
                    {
                        cout<<"This family cannot be found\n";
                    }
                    cout<<"Press F for check other family \nPress any key for return to main menu\n";
                        cin>>press2;
                        if(press2=="F"||press2=="f")
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            continue;
                        }
                        else
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            break;
                        }
            }

        }
        else if(press=="5")
        {
            cout<<"Good bye\n";
            break;
        }
        else
        {
            cout<<"Invalid error\n";
            cin.clear();
            cin.ignore(5000,'\n');
        }
    }
}
