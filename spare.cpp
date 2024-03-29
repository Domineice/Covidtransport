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
    cout<<"Amount of family by time\n";
     cout<<"======================================================================\n";
    cout <<setprecision(2)<<fixed;
    cout<<"____________________________________\n";
    cout<<"|     Time    |   Amount of family  |\n";
    cout<<"|-------------|---------------------|\n";

    double xx=4.00;
    int x=0;
    for(int i=0;i<36;i++)
    {
        if(xx>=bb.getopen()&&xx<bb.getclose())
        {
                cout<<"|";
                if(i<12)
                    cout<<" ";
                cout<<xx<<" - ";
                if(i<11)
                    cout<<" ";
                xx+=0.30;
                cout<<xx<<"|          ";
                x=0;
                for(int xxx=bb.gettime(i);xxx>0;xxx/=10)
                    x++;
                x=6-x;
if(bb.gettime(i)==0)
                    x--;
                if(bb.gettime(i)<bb.getpeople())
                    cout<<"     ";
                else
                    cout<<"X    ";
                for(int j=0;j<x;j++)
                    cout<<" ";
                cout<<bb.gettime(i)<<"|\n";
        }
        else
            xx+=0.30;
            i++;
        if(xx>=bb.getopen()&&xx<bb.getclose())
        {
                cout<<"|";
                if(i<12)
                    cout<<" ";
                cout<<xx<<" - ";
                if(i<11)
                    cout<<" ";
                xx+=0.70;
                cout<<xx<<"|          ";
                x=0;
                for(int xxx=bb.gettime(i);xxx>0;xxx/=10)
                    x++;
                x=6-x;
                if(bb.gettime(i)==0)
                    x--;
                if(bb.gettime(i)<bb.getpeople())
                    cout<<"     ";
                else
                    cout<<"X    ";
                for(int j=0;j<x;j++)
                    cout<<" ";

                cout<<bb.gettime(i)<<"|\n";
        }
        else
            xx+=0.70;

    }
    cout<<"|_____________|______________________|\n";
}
void fflush_stdin()
{ int c;
while ((c = _getch()) != '\r' /*&& c != EOF*/); }
void letsgo()
{
    cout<<"\n     Press Enter to continue.......\n";
    cin.ignore();
    cin.clear();
   // _getche();
    fflush_stdin();
    system ("CLS");
    return;
}
void avilableshop(building bb)
{
    cout <<setprecision(2)<<fixed;
    //bb.showtime();
    cout<<"Time table of "<<bb.getname()<<" shop\n";
    cout<<"_____________________________________\n";
    cout<<"|     Time    |   Full or available  |\n";
    cout<<"|-------------|----------------------|\n";

    double xx=4.00;
    for(int i=0;i<36;i++)
    {
        if(xx>=bb.getopen()&&xx<bb.getclose())
        {
                cout<<"|";
                if(i<12)
                    cout<<" ";
                cout<<xx<<" - ";
                if(i<11)
                    cout<<" ";
                xx+=0.30;
                cout<<xx<<"|          ";
                if(bb.gettime(i)<bb.getpeople())
                    cout<<" ";
                else
                    cout<<"X";
                cout<<"           |\n";
        }
        else
            xx+=0.30;
            i++;
        if(xx>=bb.getopen()&&xx<bb.getclose())
        {
                cout<<"|";
                if(i<12)
                    cout<<" ";
                cout<<xx<<" - ";
                if(i<11)
                    cout<<" ";
                xx+=0.70;
                cout<<xx<<"|          ";
                if(bb.gettime(i)<bb.getpeople())
                    cout<<" ";
                else
                    cout<<"X";
                cout<<"           |\n";
        }
        else
            xx+=0.70;

    }
    cout<<"|_____________|______________________|\n";
}
int main(){
    cout <<setprecision(2)<<fixed;
	int i,j,k,num,full,openmin,closemin,openhour,closehour;
	double open,close;
	string name;
	char choice;
	string fam_name;
	family *pt;
	town city;
	int n=0;
	char more_st,more_fam;
	string res;
	int ent_h,ent_mn,out_h,out_mn,thick;
	double ent,out;
	int check,entt,outt;
	int t;

	while(1){
            cout<<"How many of the first group of shop?\n     ";
    cin>>num;
    system ("CLS");
    if(!num||num<0)
    {
        cout<<"Invalid input\nTry again!!\n";
    }
	else if(num==0)
    {
        cout<<"No shop open.\n";
        return 0;
    }
    else
    {
        cout<<"Start with "<<num<<" shop\n";
        letsgo();
        break;
    }
    letsgo();
    cin.clear();
    cin.ignore(5000,'\n');
	}
    int oo=0;
	vector<building> LL;
	//system("CLS");
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
    letsgo();
    cin.clear();
    cin.ignore(5000,'\n');
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

            choice=_getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
            {
                 choice=_getch();
            }
            if(choice=='Y'||choice=='y')
            {
                try
                {
                cout<<"Input full people: ";
                if(!(cin>>full))
                    throw 1;
                else if(full<0)
                    throw 1;
                while(1)
                {
                    cout<<"Do you want to input open time and close time(Y/N)?\n     ";
                    choice=_getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
            {
                 choice=_getch();
            }
                    if(choice=='Y'||choice=='y')
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
                               // cout<<openhour<<" "<<openmin<<" "<<closehour<<" "<<closemin<<endl;//
                               // cout<<open<<endl;//
                               // cout<<close<<endl;//
                                 system("CLS");
                                if(open>22.00||open<4.00||close>22.00||close<4.00)
                                {
                                    cout<<"Please add time between 4.00 to 22.00\n";
                                    letsgo();
                                }
                                else if(openmin==0)
                                {
                                    if(closemin==30)
                                    {
                                        if(open>close)
                                        {
                                            cout<<"Cannot add open time more than close time.\n";
                                            letsgo();
                                        }
                                        else
                                        {
                                            LL.push_back(building(name,full,open,close));
letsgo();
                                            break;
                                        }
                                    }
                                    else if(closemin==0)
                                    {
                                        if(open>close)
                                        {
                                            cout<<"Cannot add open time more than close time.\n";
letsgo();
                                        }
                                        else
                                        {
                                            LL.push_back(building(name,full,open,close));
                                            letsgo();
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                                        letsgo();
                                    }
                                }
                                else if(openmin==30)
                                {
                                    if(closemin==30)
                                    {
                                        if(open>close)
                                        {
                                            cout<<"Cannot add open time more than close time.\n";
                                            letsgo();
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
                                       letsgo();                                   }
                                        else
                                        {
                                            LL.push_back(building(name,full,open,close));
                                            break;
                                        }
                                    }
                                    else
                                        cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                                        letsgo();
                                }
                                else
                                {
                                    cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                                    letsgo();
                                }
                            }
                            catch (int err)
                            {
                                if(err==1)
                                    cout<<"Invalid input!!\n";

                                cin.clear();
                                cin.ignore(5000,'\n');
                                letsgo();
                            }
                        }
                        break;
                    }
                    else if(choice=='N'||choice=='n')
                    {
                        LL.push_back(building(name,full));
                        letsgo();
                        break;
                    }
                    else
                    {
                        cout<<"Try again!!\n";
                        cin.clear();
                                cin.ignore(5000,'\n');
                        letsgo();
                    }
                }
                break;
                }
                catch(int err)
                {
                                if(err==1)
                                    cout<<"Invalid input!!\n";
                                cin.clear();
                                cin.ignore(5000,'\n');
                                letsgo();
                            }
            }
            else if(choice=='N'||choice=='n')
            {
                LL.push_back(building(name));
                letsgo();
                break;
            }
            else
            {
                cout<<"Try again!!\n";
                cin.clear();
                cin.ignore(5000,'\n');
                letsgo();
            }
        }
    }
    /*for(i=0;i<num;i++)
    {
        LL[i].shownode();
    }*/
    int oper=0,oper2=0,numshop,faminint,famoutint,tt;
    double famin,famout;
    char returntime,press2,press;
    string shopname,famname;
    while(1)
    {
        cout<<"Next function?\n     Press 1 for add shop\n     Press 2 for add time to shop\n     Press 3 for show shop time\n     Press 4 for show family time\n     Press 5 for exit\n     Press :";
        press=_getch();
            while(press!='1'&&press!='2'&&press!='3'&&press!='4'&&press!='5')
            {
                 press=_getch();
            }
        system("CLS");
        if(press=='1')
        {

            /*cin.clear();
            cin.ignore(5000,'\n');*/
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
                letsgo();
                oo=0;
                continue;
            }
            while(1)
            {
                cout<<"Do you want to input full people(Y/N)?\n     ";
                choice=_getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
            {
                 choice=_getch();
            }
                if(choice=='Y'||choice=='y')
                {
                    try
                    {
                    cout<<"Input full people: ";
                    if(!(cin>>full)||full<0)
                        throw 1;
                    while(1)
                    {
                        cout<<"Do you want to input open time and close time(Y/N)?\n     ";
                        choice=_getch();
            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
            {
                 choice=_getch();
            }
                        if(choice=='Y'||choice=='y')
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
                                   // cout<<openhour<<" "<<openmin<<" "<<closehour<<" "<<closemin<<endl;//
                                    //cout<<open<<endl;//
                                  //  cout<<close<<endl;//
                                    if(open>22.00||open<4.00||close>22.00||close<4.00)
                                    {
                                        cout<<"Please add time between 4.00 to 22.00\n";
                                        letsgo();
                                    }
                                    else if(openmin==0)
                                    {
                                        if(closemin==30)
                                        {
                                            if(open>close)
                                            {
                                                cout<<"Cannot add open time more than close time.\n";
                                                letsgo();
                                            }
                                            else
                                            {
                                                LL.push_back(building(name,full,open,close));
                                                letsgo();
                                                break;
                                            }
                                        }
                                        else if(closemin==0)
                                        {
                                            if(open>close)
                                            {
                                                cout<<"Cannot add open time more than close time.\n";
                                                letsgo();
                                            }
                                            else
                                            {
                                                LL.push_back(building(name,full,open,close));
                                                letsgo();
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            cout<<"No\n";
                                            cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                                            letsgo();
                                        }
                                    }
                                    else if(openmin==30)
                                    {
                                        if(closemin==30)
                                        {
                                            if(open>close)
                                            {
                                                cout<<"Cannot add open time more than close time.\n";
                                                letsgo();
                                            }
                                            else
                                            {
                                                LL.push_back(building(name,full,open,close));
                                                letsgo();
                                                break;
                                            }
                                        }
                                        else if(closemin==0)
                                        {
                                            if(open>close)
                                            {
                                            cout<<"Cannot add open time more than close time.\n";
                                            letsgo();
                                            }
                                            else
                                            {
                                                LL.push_back(building(name,full,open,close));
                                                letsgo();
                                                break;
                                            }
                                        }
                                        else
                                            cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                                            letsgo();
                                    }
                                    else
                                    {
                                        cout<<"You must add open and close time X.00 or X.30\nTry again\n";
                                        letsgo();
                                    }
                                }
                                catch (int err)
                                {
                                     if(err==1)
                                        cout<<"Invalid input\n";
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    letsgo();
                                }
                            }
                            break;
                        }
                        else if(choice=='N'||choice=='n')
                        {
                            LL.push_back(building(name,full));
                            letsgo();
                            break;
                        }
                        else
                        {
                            cout<<"Try again!!\n";
                            cin.clear();
                            cin.ignore(5000,'\n');
                            letsgo();
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
                    letsgo();
                    }
                }
                else if(choice=='N'||choice=='n')
                {
                    LL.push_back(building(name));
                    letsgo();
                    break;
                }
                else
                {
                    cout<<"Try again!!\n";
                    cin.clear();
                    cin.ignore(5000,'\n');
                    letsgo();
                }
            }
       /* for(i=0;i<LL.size();i++)
        {
            LL[i].shownode();
        }*/
        }
        else if(press=='2')
        {
            /*cin.clear();
            cin.ignore(5000,'\n');*/
        while(1){
            check=0;
            cout<<"Input your family name: ";
            cin>>fam_name;
            pt=city.find_fam(fam_name);
            if(pt==NULL){
                pt=new family(fam_name);
                city.add_family(pt);
            }
            else check=1;
            pt->show_node();
            while(1)
            {

                cout<<"***Available shop****\n";
                for(int i=0;i<LL.size();i++)
                {
                cout<<"     "<<i+1<<") "<<LL[i].getname()<<" shop\n";
                }
                cout<<"Please select the store: ";
                cin>>res;
                system("CLS");
                try
                {
                    oper=0;
                    for(i=0;i<LL.size();i++)
                    {
                        if(res.compare(LL[i].getname())==0)
                        {
                            oper=1;
                            tt=i;

                        }

                    }
                    if(oper==0)
                        throw res;
                    while(1)
                    {
                        try
                        {
                            avilableshop(LL[tt]);
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
                                if(pt->gettime(i)!=0){
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
                                        pt->book(j,i+1);

                                    }
                                    LL[i].checkadd(t);
                                    //T[t].display();
                                    LL[i].addorder(fam_name,ent,out);
                                    cout<<"Your register has been successful\n";
                                    letsgo();
                                    //LL[i].shownode();
                                }
                            }
                            break;
                        }
                        catch(int err)
                        {
                            if(err==0)
                            {
                                cout<<"This time is full\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                returntime=_getch();
                                if(returntime=='F'||returntime=='f')
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    system ("CLS");
                                    break;
                                }
                                //cin.clear();
                                  //  cin.ignore(5000,'\n');
                                    system ("CLS");
                            }
                            else if(err==1)
                            {
                                cout<<"Invalid input\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                returntime=_getch();
                                if(returntime=='F'||returntime=='f')
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    system ("CLS");
                                    break;
                                }
                              //  cin.clear();
                                   // cin.ignore(5000,'\n');
                                    system ("CLS");
                            }
                            else if(err==2)
                            {
                                cout<<"This time you must stay home\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                returntime=_getch();
                                if(returntime=='F'||returntime=='f')
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    system ("CLS");
                                    break;
                                }
                               // cin.clear();
                               // cin.ignore(5000,'\n');
                                system ("CLS");
                            }
                            else if(err==3)
                            {
                                cout<<"Cannot add open time more than close time\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                returntime=_getch();
                                if(returntime=='F'||returntime=='f')
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    system ("CLS");
                                    break;
                                }
                               // cin.clear();
                               // cin.ignore(5000,'\n');
                                system ("CLS");
                            }
                            else if(err==4)
                            {
                                cout<<"You must add open and close time X.00 or X.30\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                returntime=_getch();
                                if(returntime=='F'||returntime=='f')
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    system ("CLS");
                                    break;
                                }
                              //  cin.clear();
                              //  cin.ignore(5000,'\n');
                                system ("CLS");
                            }
                            else if(err==5)
                            {
                                cout<<"You have already reserved this time\n";
                                cout<<"Press F for select shop again, any key for add time again\n     ";
                                returntime=_getch();
                                if(returntime=='F'||returntime=='f')
                                {
                                    cin.clear();
                                    cin.ignore(5000,'\n');
                                    system ("CLS");
                                    break;
                                }
                              //  cin.clear();
                               // cin.ignore(5000,'\n');
                                system ("CLS");
                            }
                           // cin.clear();
                           // cin.ignore(5000,'\n');
                            system ("CLS");
                        }
                    }
                    try
                    {
                        while(1)
                        {
                            cout<<"Do you want to reserve more(Y/N)?\n     ";
                            more_st=_getch();
            while(more_st!='Y'&&more_st!='y'&&more_st!='N'&&more_st!='n')
            {
                 more_st=_getch();
            }
                            system ("CLS");
                            if(more_st=='N'||more_st=='n')
                                throw 1;
                            else if(more_st=='Y'||more_st=='y')
                                throw 2;
                            else
                            {
                                cout<<"Invalid input!!\n";
                                cin.clear();
                                cin.ignore(5000,'\n');
                                letsgo();
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
                        returntime=_getch();
                                if(returntime=='F'||returntime=='f')
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            system ("CLS");
                            break;
                        }
                      // cin.clear();
                       // cin.ignore(5000,'\n');
                        system ("CLS");
                }
            }
            try
            {
                while(1)
                {
                    cout<<"Do other families want to reserve(Y/N)?\n     ";
                    more_fam=_getch();
            while(more_fam!='Y'&&more_fam!='y'&&more_fam!='N'&&more_fam!='n')
            {
                 more_fam=_getch();
            }
                    system ("CLS");
                    if(more_fam=='N'||more_fam=='n')
                        throw 1;
                    else if(more_fam=='Y'||more_fam=='y')
                        throw 2;
                    else
                    {
                        cout<<"Invalid input!!\n";
                        cin.clear();
                        cin.ignore(5000,'\n');
                        letsgo();
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
            if(check==0)n++;
            /*cout<<"In loop"<<endl;
                cout<<n<<endl;
            for(i=0;i<n;i++)
            {
                T[i].display();
            }*/
        }
    }
        else if(press=='3')
        {
            system ("CLS");
           /* cin.clear();
            cin.ignore(5000,'\n');*/
            try
            {
                while(1)
                {
                    cout<<"***Registered shop****\n";
                    for(int i=0;i<LL.size();i++)
                    {
                        cout<<"     "<<i+1<<") "<<LL[i].getname()<<" shop\n";
                    }cout<<endl;
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
                        cout<<"======================================================================\n";
                        cout<<"Order list time\n";
                        LL[t].showorder();
                        printbuild(LL[t]);
                        cout<<endl<<"======================================================================\n";
                    }
                    else if(check==0)
                    {
                        cout<<"     This shop cannot be found\n";

                    }
                    cout<<"Press F for check other shop \nPress any key for return to main menu\n     ";
                        press2=_getch();
                        if(press2=='F'||press2=='f')
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            system ("CLS");
                            continue;
                        }
                        else
                        {
                            cin.clear();
                            cin.ignore(5000,'\n');
                            system ("CLS");
                            break;
                        }
                }
            }
            catch(int err)
            {

            }
        }
        else if(press=='4')
        {
            system ("CLS");
           /* cin.clear();
            cin.ignore(5000,'\n');*/
            while(1)
            {
                cout<<"What family do you want to see?\n     ";
            cin>>famname;
            check=1;
            pt=city.find_fam(famname);
            if(pt==NULL) check=0;
                    if(check==1)
                    {
                         cout<<"======================================================================\n";
                        cout<<"Order list time of "<<famname<<" family\n";
                        numshop=0;
                        for(int j=0;j<36;)
                        {
                            if(pt->gettime(j)!=0)
                            {

                                numshop=pt->gettime(j);
                                faminint=j;
                                while(pt->gettime(j)==numshop)
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
                         cout<<endl<<"======================================================================\n";
                    }
                    else if(check==0)
                    {
                        cout<<"This family cannot be found\n";
                    }
                    cout<<"Press F for check other family \nPress any key for return to main menu\n";
                        press2=_getch();
                        system ("CLS");
                        if(press2=='F'||press2=='f')
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
        else if(press=='5')
        {
            cout<<"Good bye\n";
            break;
        }
        else
        {
            cout<<"Invalid input!!\n";

            cin.clear();
            cin.ignore(5000,'\n');
            letsgo();
        }
    }
}
