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
//���п���
void del_account();
void transfer(int); //ת��
void enter_account();
void addmoney(int,float);
void exitYH();// �˳�ϵͳ
void functionshow();
void save();
void load();// ���ܽ���
protected:
consumer *account[20];
static int acnum;
//�˻���
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
// ��Ǯ
string get_passwd(){return passwd;}
// ȡ������
void display();
void fetchmoney(); //ȡǮ
void change_passwd();
void add_money(float);
void dec_money(float);
float get_money();
//����ת��
private:
int ID; //�����ʺ�
string passwd; // �û�����
string name; // �û�����
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
{cerr<<"��ȡ����,��������!"<<endl;
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
cout<<"��ȡ��������!"<<endl;
}
void YH::transfer(int x)
{int id;
cout<<"�������ʺ�:";
cin>>id;
int flag = 1;
int i = 0;
while((i<acnum)&&(flag))
{
if(id==account[i]->get_id()) flag = 0; else i++;
}
if(flag)
{
cout<<"�ʺŲ�����!"<<endl<<endl;
return ;
}
float b;
cout<<endl<<"��������Ҫת�ʵĽ��:";
cin>>b;
while(b<=0)
{
cout<<"��������ȷ������!"<<endl;
cout<<"$>";
cin>>b;
}
if(account[x]->get_money()<b) cout<<"�Բ���,����!!"<<endl;
else {account[x]->dec_money(b);account[i]->add_money(b);
cout<<"ת�ʳɹ�!";}
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
cout<<endl<<"����������Ӧ�Ĳ�����Ž��в���:"<<endl;
cout<<"1) �û�����"<<endl<<"2) �˻���½"<<endl<<"3) �ʻ�ע��"<<endl<<"4) �˳�ϵͳ "<<endl;
cout<<"$>";
cin>>n;
while(n<1||n>4)
{
cout<<"��������ȷ�Ĳ������!"<<endl;
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
cout<<"�������ʺ�:";
cin>>id;
int flag = 1;
int i = 0; //__page_break__
while((i<acnum)&&(flag))
{
if(id==account[i]->get_id()) flag = 0; else i++;
}
if(flag)
{
cout<<"�ʺŲ�����!"<<endl<<endl;
return;
}
cout<<"����������:";
string passw;
cin>>passw;
if(passw!=account[i]->get_passwd()) return;
account[i]->display();cin.get();cin.get();
int n;
do{system("cls");
cout<<"��ѡ����Ҫ���еĲ���:"<<endl<<"1)�鿴��Ϣ"<<endl<<"2)ȡ��"<<endl<<"3)���"<<endl<<"4)�޸�����"<<endl<<"5)ת��"<<endl<<"6)����"<<endl;
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
cout<<endl<<"�����뿪���ţ�";
cin>>id;
cout<<endl<<"�����뿪����������";
cin>>nam;
cout<<endl<<"�����뿪�����룺";
cin>>passw;
cout<<endl<<"�����������:";
cin>>m;
while(m<=0)
{
cout<<"��������ȷ������!"<<endl;
cin>>m;
}
consumer * acc = new consumer(id,nam,passw,m);
account[acnum] = acc;
cout<<"�����ɹ�!!"<<endl<<endl;
acnum++;
save();
cin.get();
return;
}
void YH::del_account()
{
int id;
cout<<endl<<"��������Ҫע�����ʻ���:";
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
cout<<"�ʺŲ�����!"<<endl<<endl;
return;
}
for(int j=i;j<acnum;j++)
{
account[j] = account[j+1];
}
account[acnum-1]=NULL;
acnum--;
cout<<"ע���ɹ�!!"<<endl<<endl;
save();
cin.get();
return;
}
void consumer::change_passwd()
{
string pwd,repwd;
cout<<"�����������룺";
cin>>pwd;
cout<<"��������һ�������룺";
cin>>repwd;
if(pwd!=repwd)
cout<<"��������������벻һ��,����������!"<<endl;
passwd=pwd;
cout<<"�����޸ĳɹ������μ�!"<<endl;cin.get();
}
void consumer::fetchmoney()
{
float m;
char ch;
do
{
cout<<endl<<"��Ҫȡ����Ǯ:"<<"$>"<<endl ;//__page_break__
cin>>m;
while(m<=0)
{
cout<<"��������ȷ������!"<<endl;
cout<<"$>";
cin>>m;
}
if(money<m)
{
cout<<"�Բ����������!"
<<endl;
}
else
{money=money-m;
cout<<endl<<"�����ɹ������պ�Ǯ!"
<<endl;
}
cout<<"�Ƿ�Ҫ�������������(Y/N) "
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
cout<<endl<<"��Ҫ�����Ǯ:"<<"$>"<<endl ;
cin>>c;
while(c<=0)
{
cout<<"��������ȷ������!"<<endl;
cout<<"$>";
cin>>c;
}
money=money+c;
cout<<"�����ѳɹ�!"<<endl;
cout<<"�Ƿ�Ҫ�������������(Y/N) "<<endl;
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
cout<<"* �û�������"<<name<<endl;
cout<<"* �ʺţ� "<<ID<<endl;
cout<<"* ���: "<<money<<endl;
cout<<"**********************************"<<endl;
}
void YH::exitYH()
{
cout<<endl<<"��л��Ա����д������ϵͳ��֧��,��ӭ�´ι���!"<<endl;
exit(0);
}
