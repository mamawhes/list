#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"

//�������ܣ���ʼ�� 
list *ListInit(type mytype)//�������� 
{
	list *newlist=(list*)malloc(sizeof(list));//�½�list���� 
	newlist->head=NULL;//ָ��յ�ַ 
	newlist->dataType=mytype;//����������� 
	newlist->number=0;//�б����� 
	return newlist;//����newlist
	
}
//�������ܣ����Ԫ����ĩβ 
void ListAdd(list *mylist,var data)//list�ṹ��ָ�룬�������� 
{
	link *p=NULL,*pr=mylist->head;//�½�linkָ�룬p��ָ�����ڴ棬pr���ͷָ�� 
	p=(link*)malloc(sizeof(link));//�½��ڴ� 
	if(mylist->head==NULL)//�б�Ϊ�յ���� 
		mylist->head=p;//ֱ�ӻ��һ��Ԫ�� 
	else//����Ԫ�ص���� 
		{
			while(pr->next!=NULL)//���������ҵ����βָ�� 
				pr=pr->next;
			pr->next=p;//ĩ�ڵ�ָ��ָ���½ڵ� 
		}
	p->data=data;//����������� 
	p->next=NULL;//���½ڵ���Ϊ��β 
	mylist->number++;//�ڵ��� +1  
}
//�������ܣ�������������������� 
void ListDisplay(list *mylist)//list�ṹ��ָ��
{
	link *pr=mylist->head;//pr���ͷָ�� 
	int i=1;
		if(mylist->head==NULL)//����Ϊ�� 
		{
			printf("����Ϊ��\n");
		}
		else //����Ϊ�� 
		{
			ListDisplay_printType(mylist);//������������͡��ڵ���� 
			while(1)
			{
				printf("��%d���ڵ�����Ϊ:",i);//�����һ���ڵ� 
				ListDisplay_printData(pr->data,mylist->dataType);//����ڵ����� 
				printf("\n"); 
				if(pr->next==NULL)//���������ҵ����βָ��ʱ����ѭ�� 
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
		case var_short:printf("��������short��");break;
		case var_int:printf("��������int��");break;
		case var_byte:printf("��������byte��");break;
		case var_uint:printf("��������uint��");break;
		case var_char:printf("��������char��");break;
		case var_float:printf("��������float��");break;
		
	}
	printf(",����%d��Ԫ��\n",mylist->number);
}
//�������ܣ������ݲ�����������λ�� 
int ListInsert(list* mylist,int num,var data)//list�ṹ��ָ�룬����λ�ã��������� 
{
	link *pr=mylist->head,*p=NULL,*temp=NULL;
	p=(link*)malloc(sizeof(link));//���ڴ� 
	int i;
	
	if(num>mylist->number)//�ж�λ���Ƿ���� 
	{
		free(p);
		return 0;
	}
	else
	{
		for(i=1;i<num-1;i++)// ���������ڲ���Ľڵ�֮ǰ����ѭ��
			pr=pr->next;
		temp=pr->next;//��ʱָ���������һ���ڵ��ַ 
		pr->next=p;//��һ���ڵ�ָ���Ϊ�½�ָ�� 
		p->data=data;//��ֵ 
		p->next=temp;//��ָ������ʱָ�� 
		mylist->number++;//�ڵ��� +1		
		return 1;
	}
}
//��������������Ԫ�� 
var ListIndex(list *mylist,int num)//list�ṹ��ָ�� ,Ԫ�ر�� 
{
	link *pr=mylist->head;//pr���ͷָ�� 
	int i=1;
	var data;
	data.var_int=0;
	if(num>mylist->number)//�ж�λ���Ƿ���� 
	{
		return data;
	}
		
	else //����Ϊ�� 
	{	
		while(1)
		{
			if(i==num)//���������ҵ�ָ���ڵ�ʱ����ѭ�� 
				break;
			else
			{
				pr=pr->next;
				i++; 
			}				
		}
	return pr->data;//�������� 	
	}
	
}
//ɾ������Ԫ�� 
int ListRemoveAt(list *mylist,int num)//list�ṹ��ָ�룬Ԫ�ر�� 
{
	link *pr=mylist->head,*temp=NULL;//pr���ͷָ�� 
	int i=1;
	if(num>mylist->number)//�ж�λ���Ƿ���� 
		return 0;
	else
	{
		while(1)
		{
			if(i==num-1)//���������ҵ�ָ���ڵ��ǰһ���ڵ�ʱ����ѭ�� 
				break;
			
			else
			{
				pr=pr->next;
				i++; 
			}	
		} 
	temp=pr->next;//���ָ���ڵ�ָ�� 
	pr->next=pr->next->next;//��ָ���ڵ��ǰһ�ڵ�ָ��ָ���ڵ�ĺ�һ�ڵ� 
	free(temp);	//�ڴ���� 
	mylist->number--;//�ڵ���-1	
	return 1;		
	}
}
//�������ܣ������ض�Ԫ��λ�� 
int ListIndexOf(list *mylist,var data)//list�ṹ��ָ�룬Ԫ������ 
{
	link *pr=mylist->head;//pr���ͷָ�� 
	int i=1;
	while(1)
	{
		if(!DataCompare(pr->data,data,mylist->dataType))//����ڵ����������������� 
			return i;//������� 
		if(pr->next==NULL)//���������ҵ����βָ������ѭ�� 
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
//�������ܣ��Ӵ�С����Ԫ�� 
void ListSort(list *mylist)//list�ṹ��ָ��
{
	link *pr=mylist->head,*p=NULL,*templink=NULL;//pr���ͷָ��  
	var *array=NULL,temp;//����var���������һ����ʱ���� 
	int i=0,j;
	array=(var*)malloc(sizeof(var)*(mylist->number-1));//�����ڴ�ռ� 
	while(1)//ʹarray������������������ݣ�����ԭ���� 
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
	
	for(i=0;i<mylist->number-1;i++)//��array���齫�������� 
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
	//�½��������ź�������鸳ֵ�������� 
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
	free(array);//�������� 
	
	
}
