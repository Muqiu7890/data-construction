#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define OK 1
#define OVERFLOW -2 
#define ERROR 0

typedef int QElemType,Status; 

typedef struct QNode {
	QElemType data;
	struct QNode *next; 
} QNode;

typedef struct {
	QNode *front;
	QNode *rear;
}LinkQueue;

//��ʼ��
Status InitQueue (LinkQueue *q)
{
	q->front = q->rear = (QNode *)malloc(sizeof(QNode));
	if(!q->front) exit(OVERFLOW);  //����ʧ�� 
	q->rear->next = NULL; //ͷ���front���� 
	return OK; 
 } 

//����
Status DestoryQueue (LinkQueue *q) 
{
	while(q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
		}
		return OK; 
}

 //���
 Status InQueue (LinkQueue *q,QElemType e) {
 	QNode *p;
 	p = (QNode *) malloc (sizeof(QNode)); //����ռ� 
	 if(!p) exit(OVERFLOW);
	 p->data = e;
	 p->next = NULL;
	 q->rear->next = p;  //β�ڵ����һ�ڵ�ָ���½ڵ� 
	 q->rear = p; //�½ڵ�Ϊ��β 
	 return OK; 
 }
 
 //ɾ����ͷ 
 Status DeQueue (LinkQueue *q,QElemType *e) {
 	if(q->front == q->rear) return ERROR; //�ӿ� 
 	QNode *p; 
	 p = q->front->next; //��ͷ 
	 *e = p->data;
	q->front->next = p->next;
	if(q->rear == p) q->rear = q->front; //���������ֻ��һ��Ԫ�� 
	free(p);
	return OK;
 }
 
 //�ն�
 Status EmptyQueue(LinkQueue q) 
 {
 	if(q.front->next == NULL)
 	printf("empty");
 	return OK;
 }
 
 //��ӡ
 Status PrintQueue(LinkQueue q)
 {
 	QNode *p;
 	p = q.front->next;
 	while(p != NULL) 
 	{
 		printf("%d ",p->data);
 		p = p->next;
	 }
	 printf("\n");
	 return OK;
  } 
 
 int main() {
 	int d;
 	LinkQueue q;
 	InitQueue(&q);
 	InQueue(&q,8);
 	InQueue(&q,7);
 	PrintQueue(q);
	DeQueue(&q,&d);
 	PrintQueue(q);
 	DestoryQueue(&q);
 	PrintQueue(q);
 	return 0;
 } 
  
