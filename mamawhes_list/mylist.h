#ifndef __MYLIST_H__
#define __MYLIST_H__

union v//���ù����壬����Ϊ���ֽ� 
{
	short var_short;
	char var_char;
	int var_int;
	float var_float;
	unsigned char var_byte;
	unsigned int var_uint;
	
} ;
typedef union v var;
typedef enum type//ö�����ͣ����ڴ��ݱ������� 
{
	var_short,
	var_char,
	var_float,
	var_int,
	var_byte,
	var_uint
} type;

typedef struct link
{
	var data;//�������� 
	struct link *next;//��һ���ڵ��ָ�� 
} link;

typedef struct list
{
	type dataType;//�������� 
	link *head;//����ͷָ�� 
	unsigned int number;//�ڵ���� 
} list;
 
//�������ܣ���ʼ�� 
list *ListInit(type mytype);//�������� 

//�������ܣ����Ԫ����ĩβ 
void ListAdd(list *mylist,var data);//list�ṹ��ָ�룬�������� 

//�������ܣ�������������������� 
void ListDisplay(list *mylist);//list�ṹ��ָ��

void ListDisplay_printData(var data,type dataType);
void ListDisplay_printType(list *mylist);

//�������ܣ������ݲ�����������λ�� 
int ListInsert(list* mylist,int num,var data);//list�ṹ��ָ�룬����λ�ã��������� 

//��������������Ԫ�� 
var ListIndex(list *mylist,int num);//list�ṹ��ָ�� ,Ԫ�ر�� 

//ɾ������Ԫ�� 
int ListRemoveAt(list *mylist,int num);//list�ṹ��ָ�룬Ԫ�ر�� 

//�������ܣ������ض�Ԫ��λ�� 
int ListIndexOf(list *mylist,var data);//list�ṹ��ָ�룬Ԫ������ 

int DataCompare(var data1,var data2,type dataType);

//�������ܣ��Ӵ�С����Ԫ�� 
void ListSort(list *mylist);//list�ṹ��ָ��
#endif
