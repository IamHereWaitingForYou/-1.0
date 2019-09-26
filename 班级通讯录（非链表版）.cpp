#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
char score; /*编号*/
char name[10]; /*姓名*/
char num[15]; /*号码*/
char email[20]; /*邮箱*/
char age[8]; /*年龄*/
char adds[20]; /*住址*/
}Person;
Person pe[80];
int menu_select()
{
char c;
do{
system("cls");
printf("\t\t *****通讯录***** \n");
printf("\t\t┌───────┐\n");
printf("\t\t│1. 添加记录 │\n");
printf("\t\t│2. 显示记录 │\n");
printf("\t\t│3. 删除记录 │\n");
printf("\t\t│4. 查询记录 │\n");
printf("\t\t│5. 修改记录 │\n");
printf("\t\t│6. 保存记录 │\n");
printf("\t\t│0. 退出程序 │\n");
printf("\t\t└───────┘\n");
printf("\t\t 请您选择(0-6):");
c=getchar();
}while(c<'0'||c>'6');
return(c-'0');
}
int Input(Person per[],int n)
{
int i=0;
char sign,x[10];
while(sign!='n'&&sign!='N')
{
printf("\t 编号:");
scanf("\t%d",&per[n+i].score);
printf("\t 姓名:");
scanf("\t%s",per[n+i].name);
printf("\t 年龄:");
scanf("\t%s",per[n+i].age);
printf("\t 电话号码:");

scanf("\t%s",per[n+i].num);
printf("\t 通讯住址:");
scanf("\t%s",per[n+i].adds);
printf("\t 电子邮箱:");
scanf("\t%s",per[n+i].email);
gets(x);
printf("\n\t 是否继续添加?(Y/N)");
scanf("\t%c",&sign);
i++;
}
return(n+i);
}
void Display(Person per[],int n)
{
int i;
printf("----------------------------------------------------------------------\n")
; /*格式*/
printf("编号,姓名,年龄,电话号码,通讯地址,电子邮箱\n");
printf("----------------------------------------------------------------------\n")
;
for(i=1;i<n+1;i++)
{
printf("%-5d%-8s%-6s%-13s%-15s%-15s\n",per[i-1].score,per[i-1].name,per[i-1].age,
per[i-1
].num,per[i-1].adds,per[i-1].email);
if(i>1&&i%10==0)
{
printf("\t-----------------------------------\n");
printf("\t");
system("pause");
printf("\t-----------------------------------\n");
}
}
printf("----------------------------------------------------------------------\n")
;
system("pause");
}
int Delete_a_record(Person per[],int n)
{
char s[20];
int i=0,j;
printf("\t 请输入想删除记录中的名字:");
scanf("%s",s);
while(strcmp(per[i].name,s)!=0&&i<n) i++;
if(i==n)
{
printf("\t 通讯录中没有此人!\n");
return(n);
}
for(j=i;j<n-1;j++)
{
strcpy(per[j].num,per[j+1].num);
strcpy(per[j].name,per[j+1].name);
strcpy(per[j].age,per[j+1].age);
strcpy(per[j].adds,per[j+1].adds);
strcpy(per[j].email,per[j+1].email);
per[j].score=per[j+1].score;
}
printf("\t\t\t 已经成功删除!\n");
return(n-1);
}
void Query_a_record(Person per[],int n)
{
int m;
printf("\t\n 请选择查询方式:\n");
printf("\t┌──────┐\n");
printf("\t│1------姓名 │\n");
printf("\t│2------电话 │\n");
printf("\t│3------地址 │\n");
printf("\t│4------返回 │\n");
printf("\t└──────┘\n");
printf("请选择:");
scanf("%d",&m);
while(m!=1&&m!=2&&m!=3&&m!=4)
{
printf("输入错误，请重新选择:");
scanf("%d",&m);
}
if(m==1)
{
char s[20];
int i=0;
printf("\t 请输入想查询的姓名:");
scanf("\t%s",s);
while(strcmp(per[i].name,s)!=0&&i<n) i++;
if(i==n)
{
printf("\t 通讯录中没有此人!\n");
return;
}
printf("\t 此人编号: %d\n",per[i].score);
printf("\t 此人年龄: %s\n",per[i].age);
printf("\t 电话号码: %s\n",per[i].num);
printf("\t 通讯地址: %s\n",per[i].adds);
printf("\t 电子邮箱: %s\n",per[i].email);
}
if(m==2)
{
char s[20];
int i=0;
printf("\t 请输入想查询的电话:");
scanf("\t%s",s);
while(strcmp(per[i].num,s)!=0&&i<n) i++;
if(i==n)
{
printf("\t 通讯录中没有此人!\n");
return;
}
printf("\t 此人编号: %d\n",per[i].score);
printf("\t 此人姓名: %s\n",per[i].name);
printf("\t 此人年龄: %s\n",per[i].age);
printf("\t 通讯地址: %s\n",per[i].adds);
printf("\t 电子邮箱: %s\n",per[i].email);
}
if(m==3)
{
char s[20];
int i=0;
printf("\t 请输入想查询的地址:");
scanf("\t%s",s);
while(strcmp(per[i].adds,s)!=0&&i<n) i++;
if(i==n)
{
printf("\t 通讯录中没有此人!\n");
return;
}
printf("\t 此人编号: %d\n",per[i].score);
printf("\t 此人姓名: %s\n",per[i].name);

printf("\t 此人年龄: %s\n",per[i].age);
printf("\t 电话号码: %s\n",per[i].num);
printf("\t 电子邮箱: %s\n",per[i].email);
}
}
void Change(Person per[],int n)
{
char s[20];
int i=0;
printf("\t 请输入想修改的记录中的名字:");
scanf("%s",s);
while(strcmp(per[i].name,s)!=0&&i<n) i++;
if(i==n)
{
printf("\t 通讯录中没有此人!\n");
return;
}
printf("\t 编号:");
scanf("\t%d",&per[i].score);
printf("\t 姓名:");
scanf("\t%s",per[i].name);
printf("\t 年龄:");
scanf("\t%s",per[i].age);
printf("\t 电话号码:");
scanf("\t%s",per[i].num);
printf("\t 通讯住址:");
scanf("\t%s",per[i].adds);
printf("\t 电子邮箱:");
scanf("\t%s",per[i].email);
printf("\t 修改成功！");
}
void WritetoText(Person per[],int n)
{
int i=0;
FILE *fp; /*定义文件指针*/
char filename[20]; /*定义文件名*/
printf("\t 保存到文件\n"); /*输入文件名*/
printf("\t 请输入所保存的文件名:");
scanf("\t%s",filename);
if((fp=fopen(filename,"w"))==NULL)
{
printf("\t 无法打开文件\n");
system("pause");
return;
}
fprintf(fp,"****************************************** 通 讯 录******************************************\n");
fprintf(fp,"编号,姓名,年龄,电话号码,通讯地址,电子邮箱\n");
fprintf(fp,"---------------------------------------------------------------------------------------\n");
while(i<n)
{
fprintf(fp,"%-3d\t%-6s\t%-3s\t%-13s\t%-20s\t%-20s\n",per[i].score,per[i].name,per
[i].age,per[i].num,per[i].adds,per[i].email);
i++;
}
fprintf(fp,"----------------------------------------------------------------------------------\n");
fprintf(fp,"*************************************** 共 有 %d 条 记 录*********************************\n",n);
fclose(fp); /*关闭文件*/
printf("保存成功!\n");
}
int main() /*主函数*/
{
int n=0;
for(;;)
{
switch(menu_select())
{
case 1:
printf("\n\t 添加记录到通讯录\n"); /*添加记录*/
n=Input(pe,n);
break;
case 2:
printf("\n\t\t\t 通讯录记录表\n"); /*显示记录*/
Display(pe,n);
break;
case 3:
printf("\n\t 从通讯录中删除记录\n");
n=Delete_a_record(pe,n); /*删除记录*/
printf("\t");
system("pause");
break;
case 4:
printf("\n\t 在通讯录中查找记录\n");
Query_a_record(pe,n); /*查找记录*/
printf("\t");

system("pause");
break;
case 5:
printf("\n\t 修改通讯录中的记录\n");
Change(pe,n); /*修改数据*/
printf("\t");
system("pause");
break;
case 6:
printf("\n\t 保存功能\n");
WritetoText(pe,n); /*保存数据*/
printf("\t");
system("pause");
break;
case 0:
printf("\n\t\t 谢谢使用，再见!\n"); /*结束程序*/
printf("\n\t\t");
system("pause");
exit(0);
}
}
}
