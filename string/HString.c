#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//�Ѵ�
 typedef struct { 
 char *ch;
 int len;
 }HString; 
 
 
//����ʼ��
void initString(HString *s) {
	s->ch = NULL;
	s->len = 0;
} 
 
//��ֵ
int assignString(HString *s,char *chars) {
	int i;
	if(s ==	NULL || chars == NULL) return 0;
	s->len = strlen(chars);
	if(s->len != 0) {
		if(s->ch != NULL) free(s->ch);
		s->ch = (char *)malloc((s->len + 1) * sizeof(char)); //0�ŵ�Ԫ������ 
		for(i = 1 ; i <= s->len ;i++) {
		s->ch[i] = chars[i-1]; 
	}
	}
	else s->ch = NULL; //chars ����Ϊ0��sΪ�մ�
	return 1;	
} 

//������
int insertString(HString *s,int pos,const HString t) {
	int i;
	char *temp; 
	if(s == NULL || s->ch == NULL || pos < 1 || t.ch == NULL || pos > s->len) {
		return 0;
	}
	temp = (char *)malloc((s->len + t.len + 1) * sizeof(char));
	if(temp == NULL) {
		return 0;
	}
	for(i = 1 ; i < pos ; i++)
	temp[i] = s->ch[i];
	for(i = pos ; i < pos + t.len ; i++)
		temp[i] = t.ch[i - pos + 1];
	for(i = pos + t.len ; i <= s->len + t.len ; i++) 
		temp[i] = s->ch[i - t.len];
		free(s->ch);
		s->ch = temp;
		s->len = s->len + t.len;
		return 1;
}

//��ɾ��
int delString(HString *s,int pos,int len) {
	int i;
	char *temp; 
	if(s == NULL || s->ch == NULL || pos > s->len - len + 1 || len < 0 || pos < 1) return 0;
	temp = (char *)malloc((s->len - len + 1) * sizeof(char));
	if(temp == NULL) return 0;
	for(i = 1 ; i < pos ; i++)
	temp[i] = s->ch[i];
	for(i = pos ; i <= s->len - len ; i++) {
		temp[i] = s->ch[i + len];
	} 
	free(s->ch);
	s->ch = temp;
	s->len = s->len -len;
	return 1;
} 

//������
int catString(HString *s,HString t) {
	int i;
	if(s == NULL || s->ch == NULL || t.ch == NULL) return 0;
	s->ch = (char *)realloc(s->ch,(s->len + t.len + 1) * sizeof(char));
	if(s->ch == NULL) return 0;
	for(i = s->len + 1 ; i <= t.len + s->len ; i++) 
	s->ch[i] = t.ch[i - s->len];
	s->len = s->len + t.len;
	return 1;
} 

//���Ӵ�
int subString(HString *t, int pos,int len,HString s) {
	int i;
	if(t == NULL || pos < 1 || pos > s.len || len < 0 || len > s.len - pos + 1 || s.ch == NULL) return 0;
	t->len = len;
	if(t->ch != NULL) free(t->ch); //���t 
	t->ch = (char *)malloc((t->len + 1) * sizeof(char));
	for(i = 1; i <= t->len; i++) {
		t->ch[i] = s.ch[pos + i - 1];
	} 
	return 1;
} 

//��ӡ
void printString(HString *s){
  int i;
  for(i = 1; i <= s->len; i++)
    printf("%c", s->ch[i]);
    printf("\n");
}
 
int main() 
{
	HString s,t,y;
	char s1[] = "charcter";
	char s2[] = "xy";
	//��ʼ�� 
	initString(&s);
	initString(&t);
	initString(&y);
	//��ֵ 
	assignString(&s,s1);
	assignString(&t,s2);
	printString(&s);
	//���� 
	insertString(&s,2,t);
	printString(&s);
	//ɾ�� 
	delString(&s,2,4);
	printString(&s);
	// ����
	catString(&s,t); 
	printString(&s);
	//�Ӵ�
	subString(&y,2,4,s);
	printString(&y);
	return 0;
	
}


 
