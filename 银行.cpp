#include<iostream>
#include <string>
#include<stdlib.h>
#include<fstream>
using namespace std;
class consumer;
class YH
{
public:
YH();
void set_account();
//银行开户
void del_account();
void transfer(int); //转账
void enter_account();
void addmoney(int,float);
void exitYH();// 退出系统
void functionshow();
void save();
void load();// 功能界面
protected:
consumer *account[20];
static int acnum;
//账户数
};
int YH::acnum=0;
YH::YH()
{
//for(int i=0;i<20;i++)
//{
//account[i] = NULL;
//}
}
class consumer:public YH
{
public:
friend class YH;
consumer(int id,string Name,string PassWord,float m)
{
ID=id;name=Name;money=m;passwd=PassWord;
}
consumer(){ID=0;name='0';money=0;passwd='0';}
int get_id(){return ID;}
void savemoney();
// 存钱
string get_passwd(){return passwd;}
// 取得密码
void display();
void fetchmoney(); //取钱
void change_passwd();
void add_money(float);
void dec_money(float);
float get_money();
//卡卡转帐
private:
int ID; //开户帐号
string passwd; // 用户密码
string name; // 用户姓名
float money;
};
void YH::save()
{ofstream ofile("bankdat.dat",ios::out);
ofstream outfile("bankdat.dat",ios::out);
int n=0;
outfile<<acnum<<" ";
for(;n<acnum;n++)
{outfile<<account[n]->ID<<" ";
outfile<<account[n]->money<<" ";
outfile<<account[n]->name<<" ";
outfile<<account[n]->passwd<<" ";
}
outfile.close(); //__page_break__
}
void YH::load()
{ifstream infile("bankdat.dat",ios::in);
if(!infile)
{cerr<<"读取错误,无资料中!"<<endl;
return;
}
int n=0;
int id,m;
string nam,passw;
infile>>acnum;
for(;n<acnum;n++)
{infile>>id;
infile>>m;
infile>>nam;
infile>>passw;account[n]->passwd;
consumer * acc = new consumer(id,nam,passw,m);
account[n] = acc;
}
infile.close();
cout<<"读取资料正常!"<<endl;
}
void YH::transfer(int x)
{int id;
cout<<"请输入帐号:";
cin>>id;
int flag = 1;
int i = 0;
while((i<acnum)&&(flag))
{
if(id==account[i]->get_id()) flag = 0; else i++;
}
if(flag)
{
cout<<"帐号不存在!"<<endl<<endl;
return ;
}
float b;
cout<<endl<<"请输入你要转帐的金额:";
cin>>b;
while(b<=0)
{
cout<<"请输入正确的数字!"<<endl;
cout<<"$>";
cin>>b;
}
if(account[x]->get_money()<b) cout<<"对不起,金额不够!!"<<endl;
else {account[x]->dec_money(b);account[i]->add_money(b);
cout<<"转帐成功!";}
return;
}
void consumer::add_money(float x)
{money=x+money;}
void consumer::dec_money(float x)
{money=money-x;}
void YH::addmoney(int x,float y)
{account[x]->money=account[x]->money-y;
}
float consumer::get_money()
{return money;}
int main()
{YH yh;
yh.functionshow();
}
void YH::functionshow()
{
int n;
do
{system("cls"); load();
cout<<endl<<"请你输入相应的操作序号进行操作:"<<endl;
cout<<"1) 用户开户"<<endl<<"2) 账户登陆"<<endl<<"3) 帐户注销"<<endl<<"4) 退出系统 "<<endl;
cout<<"$>";
cin>>n;
while(n<1||n>4)
{
cout<<"请输入正确的操作序号!"<<endl;
cout<<"$ >";
cin>>n;
}
switch(n)
{
case 1: set_account();
break;
case 2:enter_account();break;
case 3: del_account();
break;
case 4: exitYH();
break;
}
cin.get();
}
while(true);
}
void YH::enter_account()
{int id;
cout<<"请输入帐号:";
cin>>id;
int flag = 1;
int i = 0; //__page_break__
while((i<acnum)&&(flag))
{
if(id==account[i]->get_id()) flag = 0; else i++;
}
if(flag)
{
cout<<"帐号不存在!"<<endl<<endl;
return;
}
cout<<"请输入密码:";
string passw;
cin>>passw;
if(passw!=account[i]->get_passwd()) return;
account[i]->display();cin.get();cin.get();
int n;
do{system("cls");
cout<<"请选择你要进行的操作:"<<endl<<"1)查看信息"<<endl<<"2)取款"<<endl<<"3)存款"<<endl<<"4)修改密码"<<endl<<"5)转账"<<endl<<"6)返回"<<endl;
cin>>n;
switch(n)
{case 1: account[i]->display();break;
case 2: account[i]->fetchmoney();save();break;
case 3:account[i]->savemoney();save();break;
case 4:account[i]->change_passwd();save();break;
case 5:transfer(i);save();break;
case 6:return;
}cin.get();cin.get();
}
while(1);
}
void YH::set_account()
{
int id;
string nam;
string passw;
float m;
cout<<endl<<"请输入开户号：";
cin>>id;
cout<<endl<<"请输入开户人姓名：";
cin>>nam;
cout<<endl<<"请输入开户密码：";
cin>>passw;
cout<<endl<<"请输入存入金额:";
cin>>m;
while(m<=0)
{
cout<<"请输入正确的数字!"<<endl;
cin>>m;
}
consumer * acc = new consumer(id,nam,passw,m);
account[acnum] = acc;
cout<<"开户成功!!"<<endl<<endl;
acnum++;
save();
cin.get();
return;
}
void YH::del_account()
{
int id;
cout<<endl<<"请输入你要注销的帐户号:";
cin>>id;
int flag = 1;
int i = 0;
while((i<acnum)&&(flag))
{
if(id == account[i]->get_id())
{
flag = 0;
}
else
{
i++;
}
}
if(flag)
{
cout<<"帐号不存在!"<<endl<<endl;
return;
}
for(int j=i;j<acnum;j++)
{
account[j] = account[j+1];
}
account[acnum-1]=NULL;
acnum--;
cout<<"注销成功!!"<<endl<<endl;
save();
cin.get();
return;
}
void consumer::change_passwd()
{
string pwd,repwd;
cout<<"请输入新密码：";
cin>>pwd;
cout<<"请再输入一次新密码：";
cin>>repwd;
if(pwd!=repwd)
cout<<"你输入的两次密码不一样,请重新输入!"<<endl;
passwd=pwd;
cout<<"密码修改成功，请牢记!"<<endl;cin.get();
}
void consumer::fetchmoney()
{
float m;
char ch;
do
{
cout<<endl<<"你要取多少钱:"<<"$>"<<endl ;//__page_break__
cin>>m;
while(m<=0)
{
cout<<"请输入正确的数字!"<<endl;
cout<<"$>";
cin>>m;
}
if(money<m)
{
cout<<"对不起，你的余额不足!"
<<endl;
}
else
{money=money-m;
cout<<endl<<"操作成功，请收好钱!"
<<endl;
}
cout<<"是否要继续该项操作：(Y/N) "
<<endl;
cout<<"$ >";
cin>>ch;
while(ch!='n'&&ch!='N'&&ch!='Y'&&ch!='y')
{
cout<<"$ >";
cin>>ch;
}
}while(ch=='y'||ch=='Y');
}
void consumer::savemoney()
{
float c;
char ch;
do
{
cout<<endl<<"你要存多少钱:"<<"$>"<<endl ;
cin>>c;
while(c<=0)
{
cout<<"请输入正确的数字!"<<endl;
cout<<"$>";
cin>>c;
}
money=money+c;
cout<<"操作已成功!"<<endl;
cout<<"是否要继续该项操作：(Y/N) "<<endl;
cout<<"$ >";
cin>>ch;
while(ch!='n'&&ch!='N'&&ch!='Y'&&ch!='y')
{
cout<<"$ >";
cin>>ch;
}
}while(ch=='y'||ch=='Y');
}
void consumer::display()
{system("cls");
cout<<"**********************************"<<endl;
cout<<"*"<<endl;
cout<<"* 用户姓名："<<name<<endl;
cout<<"* 帐号： "<<ID<<endl;
cout<<"* 余额: "<<money<<endl;
cout<<"**********************************"<<endl;
}
void YH::exitYH()
{
cout<<endl<<"感谢你对本银行储蓄管理系统的支持,欢迎下次光临!"<<endl;
exit(0);
}
