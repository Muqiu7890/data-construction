#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//堆串
 typedef struct { 
 char *ch;
 int len;
 }HString; 
 
 
//串初始化
void initString(HString *s) {
	s->ch = NULL;
	s->len = 0;
} 
 
//赋值
int assignString(HString *s,char *chars) {
	int i;
	if(s ==	NULL || chars == NULL) return 0;
	s->len = strlen(chars);
	if(s->len != 0) {
		if(s->ch != NULL) free(s->ch);
		s->ch = (char *)malloc((s->len + 1) * sizeof(char)); //0号单元不可用 
		for(i = 1 ; i <= s->len ;i++) {
		s->ch[i] = chars[i-1]; 
	}
	}
	else s->ch = NULL; //chars 长度为0，s为空串
	return 1;	
} 

//串插入
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

//串删除
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

//串连接
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

//求子串
int subString(HString *t, int pos,int len,HString s) {
	int i;
	if(t == NULL || pos < 1 || pos > s.len || len < 0 || len > s.len - pos + 1 || s.ch == NULL) return 0;
	t->len = len;
	if(t->ch != NULL) free(t->ch); //清空t 
	t->ch = (char *)malloc((t->len + 1) * sizeof(char));
	for(i = 1; i <= t->len; i++) {
		t->ch[i] = s.ch[pos + i - 1];
	} 
	return 1;
} 

//打印
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
	//初始化 
	initString(&s);
	initString(&t);
	initString(&y);
	//赋值 
	assignString(&s,s1);
	assignString(&t,s2);
	printString(&s);
	//插入 
	insertString(&s,2,t);
	printString(&s);
	//删除 
	delString(&s,2,4);
	printString(&s);
	// 连接
	catString(&s,t); 
	printString(&s);
	//子串
	subString(&y,2,4,s);
	printString(&y);
	return 0;
	
}


 
