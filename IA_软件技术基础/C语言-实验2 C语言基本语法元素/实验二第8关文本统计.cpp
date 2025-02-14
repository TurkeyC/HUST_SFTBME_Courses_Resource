//输入一段含西文字符和中文字符的正文，统计字数、字符数和行数。(注:中文字数和字符数按一个字计算，英文字数按一个字计算，英文字符数按一个单词算)

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


		// //! 由检索知：在 UTF-8 编码中，英文字符通常占用一个字节，而中文字符占用三个字节
		// //! 由检索知：中文字符在 UTF-8 编码中通常以 1110xxxx 10xxxxxx 10xxxxxx 的形式出现，其中 x 是任意二进制位
		// else if(ch > 127 || ch < 0)
		// {
		// 	if ((ch & 0xE0) == 0xE0) // 检查是否是UTF-8编码的中文字符的首字节
		// 	{ 
		// 		character++;
		// 	}
		// }







		if(ch < 0)
		{
			//进入中文判断,判断第一个字节是否以 1110xxxx 的形式出现
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
			//进入英文与空白符判断

			if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			{
				//进入英文判断
				judge_en = 1;
				char_num++;
			}

			if(ch == ' ' || ch == '\t')
			{
				//进入空白符判断,判断空白符前是否为英文
				if(judge_en)
				{
					character++;
					judge_en = 0;
				}
				
			}
			if(ch == '\n')
			{
				line++;

				//进入换行符判断,判断换行符前是否为英文
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


		// //! 由检索知：在 UTF-8 编码中，英文字符通常占用一个字节，而中文字符占用三个字节
		// //! 由检索知：中文字符在 UTF-8 编码中通常以 1110xxxx 10xxxxxx 10xxxxxx 的形式出现，其中 x 是任意二进制位
		// else if(ch > 127 || ch < 0)
		// {
		// 	if ((ch & 0xE0) == 0xE0) // 检查是否是UTF-8编码的中文字符的首字节
		// 	{ 
		// 		character++;
		// 	}
		// }







		if(ch < 0)
		{
			//进入中文判断,判断第一个字节是否以 1110xxxx 的形式出现
			if((ch & 0xF0) == 0xE0)
			{
				character++;
				char_num++;

				
				
			}


			
			judge_en = 0;
		}
		
		else
		{
			//进入英文与空白符判断

			if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
			{
				//进入英文判断
				judge_en = 1;
				char_num++;
			}

			if(ch == ' ' || ch == '\t')
			{
				//进入空白符判断,判断空白符前是否为英文
				if(judge_en)
				{
					character++;
					judge_en = 0;
				}
				
			}
			if(ch == '\n')
			{
				line++;

				//进入换行符判断,判断换行符前是否为英文
				if(judge_en)
				{
					character++;
					judge_en = 0;
				}
				
			}
		}

	}
	printf("字数 %d\n字符数 %d\n行数 %d", character, char_num, line);
	return 0;
}