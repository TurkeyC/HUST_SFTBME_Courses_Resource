//����һ�κ������ַ��������ַ������ģ�ͳ���������ַ�����������(ע:�����������ַ�����һ���ּ��㣬Ӣ��������һ���ּ��㣬Ӣ���ַ�����һ��������)

#include<stdio.h>

int main(){
	int character = 0, char_num = 0, line = 0;
	char ch;
	int judge_en = 0;
	
	while((ch=getchar()) != EOF)
	{
		
		// if(ch == '\n')
		// {
		// 	line++;
		// 	character++;
		// }
		// else if(ch == ' ' || ch == '\t')
		// 	character++;

		// else if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
		// 	char_num++;


		// //! �ɼ���֪���� UTF-8 �����У�Ӣ���ַ�ͨ��ռ��һ���ֽڣ��������ַ�ռ�������ֽ�
		// //! �ɼ���֪�������ַ��� UTF-8 ������ͨ���� 1110xxxx 10xxxxxx 10xxxxxx ����ʽ���֣����� x �����������λ
		// else if(ch > 127 || ch < 0)
		// {
		// 	if ((ch & 0xE0) == 0xE0) // ����Ƿ���UTF-8����������ַ������ֽ�
		// 	{ 
		// 		character++;
		// 	}
		// }







		if(ch < 0)
		{
			//���������ж�,�жϵ�һ���ֽ��Ƿ��� 1110xxxx ����ʽ����
			if((ch & 0xF0) == 0xE0)
			{
				character++;
				char_num++;
				
				getchar();
				getchar();

				
			}
			



			
			judge_en = 0;
		}
		
		else
		{
			//����Ӣ����հ׷��ж�

			if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			{
				//����Ӣ���ж�
				judge_en = 1;
				char_num++;
			}

			if(ch == ' ' || ch == '\t')
			{
				//����հ׷��ж�,�жϿհ׷�ǰ�Ƿ�ΪӢ��
				if(judge_en)
				{
					character++;
					judge_en = 0;
				}
				
			}
			if(ch == '\n')
			{
				line++;

				//���뻻�з��ж�,�жϻ��з�ǰ�Ƿ�ΪӢ��
				if(judge_en)
				{
					character++;
					judge_en = 0;
				}
				
			}
		}

	}
	printf("%d %d %d", character, char_num, line);
	return 0;
}


































#include<stdio.h>

int main(){
	int character = 0, char_num = 0, line = 0;
	char ch;
	int judge_en = 0, count_cn = 0;
	
	while((ch=getchar()) != EOF)
	{
		
		// if(ch == '\n')
		// {
		// 	line++;
		// 	character++;
		// }
		// else if(ch == ' ' || ch == '\t')
		// 	character++;

		// else if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
		// 	char_num++;


		// //! �ɼ���֪���� UTF-8 �����У�Ӣ���ַ�ͨ��ռ��һ���ֽڣ��������ַ�ռ�������ֽ�
		// //! �ɼ���֪�������ַ��� UTF-8 ������ͨ���� 1110xxxx 10xxxxxx 10xxxxxx ����ʽ���֣����� x �����������λ
		// else if(ch > 127 || ch < 0)
		// {
		// 	if ((ch & 0xE0) == 0xE0) // ����Ƿ���UTF-8����������ַ������ֽ�
		// 	{ 
		// 		character++;
		// 	}
		// }







		if(ch < 0)
		{
			//���������ж�,�жϵ�һ���ֽ��Ƿ��� 1110xxxx ����ʽ����
			if((ch & 0xF0) == 0xE0)
			{
				character++;
				char_num++;

				
				
			}


			
			judge_en = 0;
		}
		
		else
		{
			//����Ӣ����հ׷��ж�

			if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			{
				//����Ӣ���ж�
				judge_en = 1;
				char_num++;
			}

			if(ch == ' ' || ch == '\t')
			{
				//����հ׷��ж�,�жϿհ׷�ǰ�Ƿ�ΪӢ��
				if(judge_en)
				{
					character++;
					judge_en = 0;
				}
				
			}
			if(ch == '\n')
			{
				line++;

				//���뻻�з��ж�,�жϻ��з�ǰ�Ƿ�ΪӢ��
				if(judge_en)
				{
					character++;
					judge_en = 0;
				}
				
			}
		}

	}
	printf("���� %d\n�ַ��� %d\n���� %d", character, char_num, line);
	return 0;
}