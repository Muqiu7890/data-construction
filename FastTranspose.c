#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
#define N 3
#define M 5

typedef struct{
	int row,col;
	int value;
}Triple;
typedef struct{
	Triple data[maxsize];
	int rows,cols,nums;
}TSMatrix;

//快速转置
void FastTranspose(TSMatrix *A,TSMatrix *B) //A原矩阵 
{
	int col,t,p,q,m;
	int num[maxsize],pos[maxsize];
	B->rows = A->cols;
	B->cols = A->rows;
	B->nums = A->nums;
	printf("%d %d %d\n",B->rows,B->cols,B->nums);
	if(B->nums) {
		for(col = 1;col <= A->cols;col++) num[col] = 0;
		for(t = 1;t < A->nums;t++) num[A->data[t].col]++;  //每一列元素个数 
		pos[1] = 1;
		for(col = 2;col < A->nums;col++) pos[col] = pos[col - 1] + num[col - 1]; //每一列元素开始的位置 
		for(p = 1;p < A->nums; p++) {
			col = A->data[p].col;
			q = pos[col];
			B->data[q].col = A->data[p].row; 
			B->data[q].row = A->data[p].col; 
			B->data[q].value = A->data[p].value;
			pos[col]++; 
		} 
	}
 } 

int main()
{
	TSMatrix A,B; 
	int i,j,k = 0;
	A.nums = 1;
	int a[N][M] = {{0,14,0,0,-5},{0,-7,0,0,0},{36,0,0,28,0}}; 
	for(i = 0; i < N;i++) {
		for(j = 0; j < M;j++) {
			if(a[i][j] != 0) {
				A.data[A.nums].row = i+1;
				A.data[A.nums].col = j+1;
				A.data[A.nums].value = a[i][j];
				A.nums++;	
		}
	}
}	
	A.rows = 3;
	A.cols = 5;
	FastTranspose(&A,&B);
	printf("转置后三元组：\n");
	for(k = 1;k < A.nums; k++) {
		printf("%d %d %d\n",B.data[k].row,B.data[k].col,B.data[k].value);
	}
	return 0;
} 
  

