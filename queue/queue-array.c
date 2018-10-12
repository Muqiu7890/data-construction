#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef int datatype;

typedef struct {
	datatype data[maxsize];
	int rear,front;
}CSeQueue;

CSeQueue* Init(CSeQueue *q)
{
	q = malloc(sizeof(CSeQueue));
	q->front = q->rear = 0;
	printf("初始化成功"); 
	return q; 
} 

 //入队
void InQueue(CSeQueue *q, int x)
{
	if(q->front == (q->rear+1) % maxsize)
	{
		printf("队满\n");
	 } else {
	 	q->data[q->rear] = x;
	 	q->rear = (q->rear+1) % maxsize;
	 	printf("入队成功\n");
	 }
  }  
  
  //出队
  void OutQueue(CSeQueue *q, datatype *x)
  {
  	if(q->front == q->rear)
  	{
  		printf("队为空\n");
	  }
	  else {
	  	*x = q->data[q->front]; 
	  	q->front = (q->front+1) % maxsize;
	  } 
   } 
   
   //判断队是否为空
   void EmptyQueue(CSeQueue *q)
   {
   	if(q->front == q->rear)
   	{
   	printf("栈为空\n");
   	printf("%d,%d\n",q->rear,q->front);
   }
   	else {
   		printf("栈不为空\n");
	   }
	} 

//打印队列元素
void PrintQueue(CSeQueue *q)
{
	if(q->front == q->rear)
	{
		printf("栈为空\n");
	}
	else{
		int len = q->rear - q->front,i;
		for(i = 0; i < len; i++)
		{
			printf("%d ",q->data[i]);
		}
	printf("\n");
	}	
}
	
	int main () {
		int d;
		CSeQueue q;
		Init(&q);
		EmptyQueue(&q);
		InQueue(&q,29);
		InQueue(&q,5);
		InQueue(&q,4);
		PrintQueue(&q);
		OutQueue(&q,&d);
		OutQueue(&q,&d);
		PrintQueue(&q);
		return 0;
	}
