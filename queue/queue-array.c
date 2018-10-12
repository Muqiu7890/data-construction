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
	printf("��ʼ���ɹ�"); 
	return q; 
} 

 //���
void InQueue(CSeQueue *q, int x)
{
	if(q->front == (q->rear+1) % maxsize)
	{
		printf("����\n");
	 } else {
	 	q->data[q->rear] = x;
	 	q->rear = (q->rear+1) % maxsize;
	 	printf("��ӳɹ�\n");
	 }
  }  
  
  //����
  void OutQueue(CSeQueue *q, datatype *x)
  {
  	if(q->front == q->rear)
  	{
  		printf("��Ϊ��\n");
	  }
	  else {
	  	*x = q->data[q->front]; 
	  	q->front = (q->front+1) % maxsize;
	  } 
   } 
   
   //�ж϶��Ƿ�Ϊ��
   void EmptyQueue(CSeQueue *q)
   {
   	if(q->front == q->rear)
   	{
   	printf("ջΪ��\n");
   	printf("%d,%d\n",q->rear,q->front);
   }
   	else {
   		printf("ջ��Ϊ��\n");
	   }
	} 

//��ӡ����Ԫ��
void PrintQueue(CSeQueue *q)
{
	if(q->front == q->rear)
	{
		printf("ջΪ��\n");
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
