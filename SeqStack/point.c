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

//ջ��˳��洢�ṹ 
#define maxsize 20
typedef struct 
{
	int data[maxsize];
	int top;
 }SeqStack;
 
//��ʼ�� 
void Init_SeqStack(SeqStack *s)
{
	//s = (SeqStack *)malloc(sizeof(SeqStack));  �ڴ˴�����һ���ռ� ջ����Ϊ�� ����ʾ��Ϊ����ռ�ĵ�ַ  
	s->top = -1;
	printf("��ʼ���ɹ�\n");
 } 
 
 //�п�ջ
 void Empty_SeqStack(SeqStack *s)
 {
 	if(s->top == -1)
 	{
 		printf("ջΪ��\n");
	 } else {
 		printf("ջ��Ϊ��\n");
	 }
  } 
  
  //��ջ
 void Push_SeqStack(SeqStack *s,int x)
  {
  	if(s->top == maxsize-1) {
  		printf("��ջ����\n"); 
	  } else {
  		s->top++;
  		s->data[s->top] = x;
	  }
  } 
  
  //��ջ
  void Pop_SeqStack(SeqStack *s,int *x)
  {
  	if(s->top == -1) {
  		printf("��ջΪ��\n");
	  }
	  else {
	  	*x = s->data[s->top];
	  	s->top--;
	  } 
  }
  
  //ȡջ��Ԫ��
  int Top_SeqStack(SeqStack *s) 
  {
  	if(s->top == -1) return 0;
  	else {
  		return s->data[s->top];
	  }
   } 
   
   //���ջ������Ԫ��
   int print_SeqStack(SeqStack s)
   {
   	if(s.top == -1) 
	   printf("ջ��\n"); 
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
