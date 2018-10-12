#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

//int main() {
//	char a = 'a';
//	int b = 123; 
//	char *pa = &a;
//	int *pb = &b;
//	
//	printf("%c,%d",&a,*pb);
//	 
//	return 0;
//}

//栈的顺序存储结构 
#define maxsize 20
typedef struct 
{
	int data[maxsize];
	int top;
 }SeqStack;
 
//初始化 
void Init_SeqStack(SeqStack *s)
{
	//s = (SeqStack *)malloc(sizeof(SeqStack));  在此处申请一个空间 栈并不为空 所显示的为申请空间的地址  
	s->top = -1;
	printf("初始化成功\n");
 } 
 
 //判空栈
 void Empty_SeqStack(SeqStack *s)
 {
 	if(s->top == -1)
 	{
 		printf("栈为空\n");
	 } else {
 		printf("栈不为空\n");
	 }
  } 
  
  //入栈
 void Push_SeqStack(SeqStack *s,int x)
  {
  	if(s->top == maxsize-1) {
  		printf("该栈已满\n"); 
	  } else {
  		s->top++;
  		s->data[s->top] = x;
	  }
  } 
  
  //出栈
  void Pop_SeqStack(SeqStack *s,int *x)
  {
  	if(s->top == -1) {
  		printf("该栈为空\n");
	  }
	  else {
	  	*x = s->data[s->top];
	  	s->top--;
	  } 
  }
  
  //取栈顶元素
  int Top_SeqStack(SeqStack *s) 
  {
  	if(s->top == -1) return 0;
  	else {
  		return s->data[s->top];
	  }
   } 
   
   //输出栈中所有元素
   int print_SeqStack(SeqStack s)
   {
   	if(s.top == -1) 
	   printf("栈空\n"); 
   else {
   	while(s.top != -1) {
   		printf("%d\n",s.data[s.top]);
   		s.top--;
	   }
   } 
}
   
   int main() 
   {
   	int d;
   	SeqStack s;
   	Init_SeqStack(&s); 
   	Empty_SeqStack(&s);
   	print_SeqStack(s);
   	Push_SeqStack(&s,3);
   	Push_SeqStack(&s,5);
   	print_SeqStack(s);
   	Pop_SeqStack(&s,&d);
   	print_SeqStack(s);
   	
   	Top_SeqStack(&s);
   	return 0;
   }
