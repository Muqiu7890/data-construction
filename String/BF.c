#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//BFģʽƥ��

int Index(char* s,int pos,char* t) {
	int i = pos,j = 0,m,n;
	m = strlen(s);
	n = strlen(t);
	while(i < m && j < n) {
		if(s[i] == t[j]) {
			i++;
			j++;
		} else {
			i = i -j + 1;
			j = 0;
		}
	}
	if(n <= j) return i-n; //ƥ��ɹ� ����ƥ�����ʼλ�� 
	else return -1;
} 

int main() {
	char* s = "ababcabcacbab";
	char* t = "cac";
	printf("%d",Index(s,3,t));
	return 0;
}
