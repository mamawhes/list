#ifndef __MYLIST_H__
#define __MYLIST_H__

union v//设置共用体，长度为四字节 
{
	short var_short;
	char var_char;
	int var_int;
	float var_float;
	unsigned char var_byte;
	unsigned int var_uint;
	
} ;
typedef union v var;
typedef enum type//枚举类型，用于传递变量类型 
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
	var data;//数据内容 
	struct link *next;//下一个节点的指针 
} link;

typedef struct list
{
	type dataType;//数据类型 
	link *head;//链表头指针 
	unsigned int number;//节点个数 
} list;
 
//函数功能：初始化 
list *ListInit(type mytype);//数据类型 

//函数功能：添加元素至末尾 
void ListAdd(list *mylist,var data);//list结构体指针，数据内容 

//函数功能：遍历链表，输出数据内容 
void ListDisplay(list *mylist);//list结构体指针

void ListDisplay_printData(var data,type dataType);
void ListDisplay_printType(list *mylist);

//函数功能：将数据插入链表任意位置 
int ListInsert(list* mylist,int num,var data);//list结构体指针，插入位置，数据内容 

//查找链表中任意元素 
var ListIndex(list *mylist,int num);//list结构体指针 ,元素编号 

//删除任意元素 
int ListRemoveAt(list *mylist,int num);//list结构体指针，元素编号 

//函数功能：查找特定元素位置 
int ListIndexOf(list *mylist,var data);//list结构体指针，元素数据 

int DataCompare(var data1,var data2,type dataType);

//函数功能：从大到小排列元素 
void ListSort(list *mylist);//list结构体指针
#endif
