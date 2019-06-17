#include<iostream> 
class num 
{ 
public: 
num(int z=0,int m=0){numerator=z; denominator=m;} 
void yuefen(int x,int y);// 定义约分函数
num operator + (num n2);// 运算符 +重载成员函数
num operator - (num n2);// 运算符 - 重载成员函数
num operator * (num n2);// 运算符 *重载成员函数
num operator / (num n2);// 运算符 / 重载成员函数
bool operator == (num n2);// 运算符 ==重载成员函数
double realnum()
{
	R=(double)numerator/denominator; 
	return R; 
	//cout<<R;
	}// 定义函数将其转化
void show();// 定义函数将其输出
private: 
int numerator,denominator; 
double R; 
}; 
void num::yuefen(int x,int y) // 分数化简函数
{ int t; 
int i; 
 if(x>y) 
 t=y; 
 else 
 t=x; 
 for(i=t;i>=1 ;i--) 
if((x%i==0)&&(y%i==0)) 
{ 
 t=i; 
 break; 
} 
if(t) 
{ 
numerator=x/t; 
denominator=y/t; 
} 
else 
{ 
numerator=x; 
denominator=y; 
} 
if(numerator==0) 
cout<<"0"<<endl; 
else 
cout<<numerator<<"/"<<denominator<<endl; 
} 
//////////////////////////////// 重载运算符函数的实现 /////////////////////////////////// 
num num::operator+(num n2) 
{ 
return 
num(numerator*n2.denominator+denominator*n2.numerator,
denominator*n2.denominator); 
} 
num num::operator-(num n2) 
{ 
return 
num(numerator*n2.denominator-denominator*n2.numerator,
denominator*n2.denominator); 
} 
num num ::operator*(num n2) 
{ 
return 
num(numerator*n2.numerator,denominator*n2.denominator)
; 
} 
num num ::operator/(num n2) 
{ 
return 
num(numerator*n2.denominator,denominator*n2.numerator)
; 
} 
bool num::operator == (num n2) 
{ 
if((numerator=n2.numerator)&&(denominator=n2.den
ominator)) 
return true; 
else 
return false; 
} 
void num::show()// 显示输出函数
{ 
if(numerator==0) 
cout<<"0"<<endl; 
else if(denominator==0) 
cout<<" 您的输入有误 !"<<endl; 
else 
cout<<numerator<<"/"<<denominator<<endl; 
} 
/////////////////////////////////////////// 主函数 //////////////////////////////////// 
int main() 
{ 
char m; 
cout<<"/////////////////////////// 有理数运算程序 //////////////////////////////"<<endl; 
cout<<" 确定进入系统？ (Y/N)"<<endl;// 提示是否进入有理数运算系统
cin>>m; 
if(m=='n'||m=='N') 
cout<<" 不进入系统！ "<<endl; 
else if(m=='y'||m=='Y') 
{ 
char n; 
cout<<" 输入两个有理数： "; 
int a,b,c,d; 
cin>>a>>b>>c>>d; 
num n1(a,b),n2(c,d),n3; 
cout<<" 您所输入的有理数 n1为："; 
n1.show(); 
cout<<" 化简后的 n1为："; 
n1.yuefen(a,b); 
cout<<" 转 化 为 实 数 后 的 n1 为 ："<<n1.realnum()<<endl; 
cout<<" 您所输入的有理数 n2为："; 
n2.show(); 
cout<<" 化简后的 n2为："; 
n2.yuefen(c,d); 
cout<<" 转 化 为 实 数 后 的 n2 为 ："<<n2.realnum()<<endl; 
cout<<" 输入您所需要的运算符： "; 
cin>>n; 
if(n=='+') 
{ 
n3=n1+n2; 
cout<<" 您所需的操作为： n1+n2="; 
n3.show(); 
cout<<" 化简后的数为： "; 
n3.yuefen(a*d+b*c,b*d); 
cout<<" 转 化 为 实 数 后 为 ："<<n3.realnum()<<endl; 
} 
else if(n=='-') 
{ 
n3=n1-n2; 
cout<<" 您所需的操作为： n1-n2="; 
n3.show(); 
cout<<" 化简后的数为： "; 
n3.yuefen(a*d-b*c,b*d); 
cout<<" 转 化 为 实 数 后 为 ："<<n3.realnum()<<endl; 
} 
else if(n=='*') 
{ 
n3=n1*n2; 
cout<<" 您所需的操作为： n1*n2="; 
n3.show(); 
cout<<" 化简后的数为： "; 
n3.yuefen(a*c,b*d); 
cout<<" 转 化 为 实 数 后 为 ："<<n3.realnum()<<endl; 
} 
else if(n=='/') 
{ 
n3=n1/n2; 
cout<<" 您所需的操作为： n1/n2="; 
n3.show(); 
cout<<" 化简后的数为： "; 
n3.yuefen(a*d,b*c); 
cout<<" 转 化 为 实 数 后 为 ："<<n3.realnum()<<endl; 
} 
else 
cout<<" 您输入的运算符不正确！ "<<endl; 
cout<<" 由==重载运算符知： "; 
if(a*d==b*c) 
cout<<"n1=n2"<<endl; 
else 
cout<<"n1!=n2"<<endl; 
} 
else 
cout<<" 您的输入有误！ "<<endl; 
 cout<<" 运算结束，您继续吗？ (Y/N)";// 提示是否继续运算
 char p; 
 cin>>p; 
if(p=='n'||p=='N') 
cout<<" 退出运算系统！ "<<endl; 
else if(p=='y'||p=='Y') 
return main(); 
else 
cout<<" 您的输入有误！ "<<endl; 
return 0; 
}
