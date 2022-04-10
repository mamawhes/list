#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"

//函数功能：初始化 
list *ListInit(type mytype)//数据类型 
{
	list *newlist=(list*)malloc(sizeof(list));//新建list类型 
	newlist->head=NULL;//指向空地址 
	newlist->dataType=mytype;//获得数据类型 
	newlist->number=0;//列表数量 
	return newlist;//返回newlist
	
}
//函数功能：添加元素至末尾 
void ListAdd(list *mylist,var data)//list结构体指针，数据内容 
{
	link *p=NULL,*pr=mylist->head;//新建link指针，p将指向新内存，pr获得头指针 
	p=(link*)malloc(sizeof(link));//新建内存 
	if(mylist->head==NULL)//列表为空的情况 
		mylist->head=p;//直接获得一个元素 
	else//存在元素的情况 
		{
			while(pr->next!=NULL)//遍历链表，找到表的尾指针 
				pr=pr->next;
			pr->next=p;//末节点指针指向新节点 
		}
	p->data=data;//获得数据内容 
	p->next=NULL;//将新节点置为表尾 
	mylist->number++;//节点数 +1  
}
//函数功能：遍历链表，输出数据内容 
void ListDisplay(list *mylist)//list结构体指针
{
	link *pr=mylist->head;//pr获得头指针 
	int i=1;
		if(mylist->head==NULL)//链表为空 
		{
			printf("链表为空\n");
		}
		else //链表不为空 
		{
			ListDisplay_printType(mylist);//输出此链表类型、节点个数 
			while(1)
			{
				printf("第%d个节点数据为:",i);//输出第一个节点 
				ListDisplay_printData(pr->data,mylist->dataType);//输出节点内容 
				printf("\n"); 
				if(pr->next==NULL)//遍历链表，找到表的尾指针时跳出循环 
					break;
				else
				{
					pr=pr->next;
					i++; 
				}
					
			}
		}
	
}

void ListDisplay_printData(var data,type dataType)
{
	switch(dataType)
	{
		case var_short:
		case var_int:
		case var_byte:
		case var_uint:
			printf("%d",data);break;
		case var_char:
			printf("%c",data.var_char);break;
		case var_float:
			printf("%f",data.var_float);break;
		
	}
}

void ListDisplay_printType(list *mylist)
{
	switch(mylist->dataType)
	{
		case var_short:printf("单链表是short型");break;
		case var_int:printf("单链表是int型");break;
		case var_byte:printf("单链表是byte型");break;
		case var_uint:printf("单链表是uint型");break;
		case var_char:printf("单链表是char型");break;
		case var_float:printf("单链表是float型");break;
		
	}
	printf(",含有%d个元素\n",mylist->number);
}
//函数功能：将数据插入链表任意位置 
int ListInsert(list* mylist,int num,var data)//list结构体指针，插入位置，数据内容 
{
	link *pr=mylist->head,*p=NULL,*temp=NULL;
	p=(link*)malloc(sizeof(link));//新内存 
	int i;
	
	if(num>mylist->number)//判断位置是否合理 
	{
		free(p);
		return 0;
	}
	else
	{
		for(i=1;i<num-1;i++)// 遍历链表，在插入的节点之前跳出循环
			pr=pr->next;
		temp=pr->next;//临时指针变量存下一个节点地址 
		pr->next=p;//下一个节点指针变为新建指针 
		p->data=data;//赋值 
		p->next=temp;//新指针获得临时指针 
		mylist->number++;//节点数 +1		
		return 1;
	}
}
//查找链表中任意元素 
var ListIndex(list *mylist,int num)//list结构体指针 ,元素编号 
{
	link *pr=mylist->head;//pr获得头指针 
	int i=1;
	var data;
	data.var_int=0;
	if(num>mylist->number)//判断位置是否合理 
	{
		return data;
	}
		
	else //链表不为空 
	{	
		while(1)
		{
			if(i==num)//遍历链表，找到指定节点时跳出循环 
				break;
			else
			{
				pr=pr->next;
				i++; 
			}				
		}
	return pr->data;//返回数据 	
	}
	
}
//删除任意元素 
int ListRemoveAt(list *mylist,int num)//list结构体指针，元素编号 
{
	link *pr=mylist->head,*temp=NULL;//pr获得头指针 
	int i=1;
	if(num>mylist->number)//判断位置是否合理 
		return 0;
	else
	{
		while(1)
		{
			if(i==num-1)//遍历链表，找到指定节点的前一个节点时跳出循环 
				break;
			
			else
			{
				pr=pr->next;
				i++; 
			}	
		} 
	temp=pr->next;//获得指定节点指针 
	pr->next=pr->next->next;//将指定节点的前一节点指向指定节点的后一节点 
	free(temp);	//内存回收 
	mylist->number--;//节点数-1	
	return 1;		
	}
}
//函数功能：查找特定元素位置 
int ListIndexOf(list *mylist,var data)//list结构体指针，元素数据 
{
	link *pr=mylist->head;//pr获得头指针 
	int i=1;
	while(1)
	{
		if(!DataCompare(pr->data,data,mylist->dataType))//如果节点数据与查找数据相等 
			return i;//返回序号 
		if(pr->next==NULL)//遍历链表，找到表的尾指针跳出循环 
			return 0;		
		else
		{
			pr=pr->next;
			i++; 
		}	
	} 
}

int DataCompare(var data1,var data2,type dataType)
{
	int re;
	switch(dataType)
	{
		
		case var_short:re=data1.var_short-data2.var_short;break;
		case var_int:re=data1.var_int-data2.var_int;break;
		case var_byte:re=data1.var_byte-data2.var_byte;break;
		case var_uint:re=data1.var_uint-data2.var_uint;break;
		case var_char:re=data1.var_char-data2.var_char;break;
		case var_float:re=data1.var_float-data2.var_float;break;
	
	}
	return re;
}
//函数功能：从大到小排列元素 
void ListSort(list *mylist)//list结构体指针
{
	link *pr=mylist->head,*p=NULL,*templink=NULL;//pr获得头指针  
	var *array=NULL,temp;//建立var类型数组和一个临时变量 
	int i=0,j;
	array=(var*)malloc(sizeof(var)*(mylist->number-1));//分配内存空间 
	while(1)//使array数组获得链表的所有数据，销毁原链表 
	{
		array[i]=pr->data; 
		templink=pr;
		if(pr->next==NULL)
		{
			free(templink);
			break;
		}
		else
		{
			
			pr=pr->next;
			free(templink);
		}
		
		i++;
	}
	
	for(i=0;i<mylist->number-1;i++)//在array数组将数据排序 
	{
		for(j=i+1;j<mylist->number;j++)
		{
			if(DataCompare(array[i],array[j],mylist->dataType)>0)
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}	
	}
	//新建链表，将排好序的数组赋值给新链表 
	p=(link*)malloc(sizeof(link));
	p->data=array[0];
	p->next=NULL;
	mylist->head=p; 
	pr=mylist->head;
	for(i=1;i<mylist->number;i++)
	{
		p=(link*)malloc(sizeof(link));
		p->data=array[i];
		p->next=NULL;
		pr->next=p;
		pr=pr->next;
	}
	free(array);//销毁数组 
	
	
}
