#include<stdio.h>
void strReverse(char s[]); 
int strLength(char s[]);
int main() 
{
	char s[1000];
	//printf("����һ���ַ���\n");
	scanf("%s",s);
	printf("��%s�ĳ���Ϊ:%d\n",s,strLength(s));
	strReverse(s);  
	printf("��ת��:%s",s);
	return 0;
}

int strLength(char s[])  /* �����ַ����ĳ��ȣ�������β��*/ 
{
	int i=0;
	while(s[++i]); //!
	return i; 	
}

void strReverse(char s[])  /* ��ת��s */
{
	int i,j;
	for(i=0,j=strLength(s)-1;i<j;i++,j--)  /* ����ͷ����s */
	{
	    char t;
		t=s[i]; 
	    s[i]=s[j]; 
	    s[j]=t; 
    }
}