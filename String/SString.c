#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAXSIZE 10 
//����˳��

typedef struct {
char ch[MAXSIZE + 1];
int len;
}SString;

//���봮
int insertString(SString *s,int pos,const SString T)
{
	int i;
	if(s->ch == NULL || s == NULL || T.ch == NULL || pos < 1 || pos > s->len + 1) {
		return 0;
	} 
	if(s->len + T.len <= MAXSIZE) { //��δ���� 
		for(i = s->len + T.len; i >= pos + T.len ; i--) {
			s->ch[i] = s->ch[i - T.len]; //B����� 
		}
		for(i = pos; i < pos + T.len; i++) {
			s->ch[i] = T.ch[i - pos];
		}
		s->len = s->len + T.len;
//		printf("%d",s->len);
	}
	else if(pos + T.len <= MAXSIZE) {  //B���� 
		for(i = MAXSIZE; i >= pos + T.len ; i--) {
			s->ch[i] = s->ch[i - T.len]; //B����� 
		}
		for(i = pos; i < pos + T.len; i++) {
			s->ch[i] = T.ch[i - pos];
		}
		s->len = MAXSIZE;
	} 
	else  //�����t����Ҳ����ȥ 
	{
		for(i = pos; i <= MAXSIZE; i++) {
			s->ch[i] = T.ch[i - pos];
		}
		s->len = MAXSIZE;
	}
	return 1;
 } 
 
 //ɾ����
int delString(SString *s,int pos,int len) 
{
	int i;
	if(s->ch == NULL || s == NULL || pos < 1 || pos > s->len - len + 1 || len < 0) {
		return 0;
	} 
	for(i = pos; i < pos + len; i++) {
	s->ch[i] = s->ch[i + len];
	}
	s->len = s->len - len;
	return 1;
 } 
 
 //����������
 int catString(SString *s,const SString T) 
 {
 	int i;
	if(s->ch == NULL || s == NULL || T.ch == NULL) {
		return 0;
	} 
	if(s->len + T.len <= MAXSIZE) { // ���Ӻ�С�����ֵ 
		for(i = s->len ; i <= s->len + T.len; i++) {
			s->ch[i] = T.ch[i - s->len]; 
		}
		s->len = s->len + T.len;
		return 1;
	} 
	else if(s->len <= MAXSIZE) {  //���Ӻ�������ֵ t���ֱ����� 
		for(i = s->len ; i < MAXSIZE; i++) {
			s->ch[i] = T.ch[i - s->len]; 
		}
		s->len = MAXSIZE;
		return 0;
	} 
  } 
  
  //���Ӵ�����
  int SubString(SString *T,SString s,int pos,int len)
  {
  	int i;
  	if(T == NULL || T->ch == NULL || len < 0 || s.ch == NULL || len > s.len - pos + 1 || pos < 0 || pos > s.len) {
  			return 0;
	  }
  	for(i = 0 ; i < len; i++) {
  		T->ch[i] = s.ch[i + pos];
	  }
	  T->len = len;
	  return 1;
   } 
   
int main() 
{
	int len,i;
	SString s,t,y;
	strcpy(s.ch,"charter");
	strcpy(t.ch,"12");
	s.len = strlen(s.ch);
	t.len = strlen(t.ch);
	insertString(&s,2,t);
	printf("%s\n",s);
	delString(&s,2,4);
	printf("%s\n",s);
	catString(&s,t);
	printf("%s\n",s);
	SubString(&y,s,2,4);
	printf("%s",y);
	return 0;
}
 
 
 
 
 
 
