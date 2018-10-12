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

//初始化
Status InitQueue (LinkQueue *q)
{
	q->front = q->rear = (QNode *)malloc(sizeof(QNode));
	if(!q->front) exit(OVERFLOW);  //分配失败 
	q->rear->next = NULL; //头结点front不动 
	return OK; 
 } 

//销毁
Status DestoryQueue (LinkQueue *q) 
{
	while(q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
		}
		return OK; 
}

 //入队
 Status InQueue (LinkQueue *q,QElemType e) {
 	QNode *p;
 	p = (QNode *) malloc (sizeof(QNode)); //申请空间 
	 if(!p) exit(OVERFLOW);
	 p->data = e;
	 p->next = NULL;
	 q->rear->next = p;  //尾节点的下一节点指向新节点 
	 q->rear = p; //新节点为队尾 
	 return OK; 
 }
 
 //删除队头 
 Status DeQueue (LinkQueue *q,QElemType *e) {
 	if(q->front == q->rear) return ERROR; //队空 
 	QNode *p; 
	 p = q->front->next; //队头 
	 *e = p->data;
	q->front->next = p->next;
	if(q->rear == p) q->rear = q->front; //特殊情况，只有一个元素 
	free(p);
	return OK;
 }
 
 //空队
 Status EmptyQueue(LinkQueue q) 
 {
 	if(q.front->next == NULL)
 	printf("empty");
 	return OK;
 }
 
 //打印
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
  
