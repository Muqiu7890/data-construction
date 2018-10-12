#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//next����

void get_next(char* t,int next[]) {
	int j = 1,k = 0; //j ��׺ k ǰ׺
	next[1] = 0;
	while(j < strlen(t)) {
		if( k == 0 || t[j] == t[k]) {
			j++;
			k++;
			if(t[j]!= t[k]) {
				next[j] = k; 
			}
			else next[j] = next[k]; //�������� 
		}
		else k = next[k];  //���ݵ���һ��ƥ���λ�� 
	} 
} 


int Index(char* s,int pos,char* t) {
	int i = pos,j = 1;
	int next[255];
	get_next(t,next);
	s[0] = strlen(s);
	t[0] = strlen(t);
//	printf("%d %d",s[0],t[0]);
//	printf("qqqqq");
	while(i <= s[0] && j <= t[0]) {
		if(j == 0 ||s[i] == t[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if(t[0] < j) return i - t[0]; //ƥ��ɹ� ����ƥ�����ʼλ�� 
	else return -1;
} 

int main()
{
	char s[] = "aaaaaaaaac";
	char t[] = "aac";
	int next[255];
	t[0] = strlen(t);
	printf("%d",Index(s,1,t));
	return 0;

 } 




