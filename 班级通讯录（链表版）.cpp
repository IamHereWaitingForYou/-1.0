#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#define N 20 
typedef struct student{ 
char tel[N]; 
char name[N]; 
char id[N]; 
struct student *next; 
}linklist; 
//创建信息
void createlist(linklist *&l){ 
int ch; 
linklist *s,*p; 
printf("*********** 创建通讯录 ***********\n"); 
printf("---- 请输入通讯者信息 ----- ：\n 请输入非零整数， 输入 0 则退出 :\n"); 
scanf("%d",&ch); 
l=(linklist *)malloc(sizeof(linklist)); 
s=l; 
while(ch!=0){ 
p=(linklist *)malloc(sizeof(linklist)); 
printf(" 请输入通讯者姓名 :"); 
scanf("%s",p->name); 
printf(" 请输入通讯者电话号 :"); 
scanf("%s",p->tel); 
printf(" 请输入通讯者身份证号 :"); 
scanf("%s",p->id); 
s->next=p; 
s=p; 
printf(" 请输入通讯者信息： \n 请输入非零整数，输入 0 则退出 :\n"); 
scanf("%d",&ch); 
} 
s->next=NULL; 
} 
//删除信息
void listdelete(linklist *&l,int t ){ 
int j=0; 
linklist *p,*q; 
p=l; 
while(p!=NULL&&j<t-1){ 
j++; 
p=p->next; 
} 
if(p==NULL) 
exit(0); 
else{ 
q=p->next; 
if(q==NULL)exit(0); 
p->next=q->next; 
printf("*************** 删除系统 **************\n"); 
printf("------- 你将删除的联系人的信息为 -------:\n"); 
printf(" 通讯者姓名 :%s\n",q->name); 
printf(" 通讯者电话号 :%s\n",q->tel); 
printf(" 通讯者身份证号 :%s\n",q->id); 
printf("******-------****** 删除成功 ******------*******\n"); 
free(q); 
} 
} 
//输出信息
void output(linklist *l){ 
linklist *p; 
p=l->next; 
printf("----***---- 输出所有联系者信息 ----***----:\n"); 
while(p!=NULL){ 
printf(" 通讯者姓名 :%s\n",p->name); 
printf(" 通讯者电话号 :%s\n",p->tel); 
printf(" 通讯者身份证号 :%s\n",p->id); 
printf("*****************************\n"); 
p=p->next; 
} 
} 
//按姓名查找
void findname(linklist *l){ 
char n[N]; 
linklist *p=l->next; 
printf("*************** 查找系统 *************\n"); 
printf("---------- 请输入要查找的姓名 ---------:\n"); 
scanf("%s",n); 
while(p!=NULL){ 
if(strcmp(p->name,n)){ 
printf("-----***-- 你要查找的资料为 --***----:\n"); 
printf(" 通讯者姓名 :%s\n",p->name); 
printf(" 通讯者电话号 :%s\n",p->tel); 
printf(" 通讯者身份证号 :%s\n",p->id); 
printf("*****************************"); 
break; 
} 
else 
p=p->next; 
} 
} 
//按电话号排序
void sorttel(linklist *&l){ 
linklist *p,*q,*s; 
q=l; 
p=q->next->next; 
q->next->next=NULL; 
while(p){ 
while(q->next&&(strcmp(p->tel,q->next->tel)>0)) 
q=q->next; 
s=p->next; 
p->next=q->next; 
q->next=p; 
p=s; 
q=l; 
} 
} 
//清空
void release(linklist *&l){ 
linklist *p,*q; 
p=l; 
q=p->next; 
while(q!=NULL){ 
free(p); 
p=q; 
q=p->next; 
} 
free(p); 
printf("-------- 数据已全部被清空 ----------\n ，***** 内存回收 *****\n"); 
} 
//主函数
int main(){ 
int i,t; 
linklist *l; 
while(1){ 
printf(" 通讯录功能如下 :\n1.建立通讯录信息 \n2.删除信息 \n3.输出信息 \n4.按姓名查找信息 \n5.按电话号排序信息 \n6.清空信息 \n7.退出 "); 
scanf("%d",&i); 
if(i<=0||i>7)break; 
switch(i){ 
case 1: 
createlist(l);break; 
case 2: 
printf("--------- 请输入第 t 个要删除的信息 ---------:\n"); 
scanf("%d",&t); 
listdelete(l,t); 
break; 
case 3: 
output(l);break; 
case 4: 
findname(l);break; 
case 5: 
sorttel(l); 
printf("-----***---&&&-- 这 是 按 电 话 号 排 序 后 的 信 息 列 表--&&&---***-----\n"); 
output(l); 
break; 
case 6: 
release(l);break; 
case 7: 
break; 
} 
} 
}
