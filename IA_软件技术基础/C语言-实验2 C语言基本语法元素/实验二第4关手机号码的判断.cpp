//长度合法>每一位都是数字>第1位合法>第2位合法
//1304567854 长度不合法
//170*56785-3 字符串中存在非数字字符
//10234567543 第2位不合法
//76045678543 第1位不合法

#include<stdio.h>

int main(){
	char phone[20];

	while(scanf("%s",phone) != EOF)//如果用户输入了Ctrl+Z，则结束循环
	{	
		//计算长度
		int length = 0;
		while (phone[length] != '\0') 
		{
			length++;
		}

		//判断长度是否合法
		if(length != 11)
		{
			printf("长度不合法\n");
			continue;
		}
		
		//判断每一位是否都是数字
		bool theBool = true;
		for(int i=0;i<length;i++)
		{
			if(phone[i]<'0'||phone[i]>'9')
			{
				printf("字符串中存在非数字字符\n");
				theBool = false;
				break;
			}
		}
		if(!theBool) continue;

		//判断第1位是否合法
		if(phone[0] != '1')
		{
			printf("第1位不合法\n");
			continue;
		}

		//判断第2位是否合法
		if(phone[1] != '3' && phone[1] != '4' && phone[1] != '5' && phone[1] != '7' && phone[1] != '8')
		{
			printf("第2位不合法\n");
			continue;
		}

	}
	return 0;  
}




// #include<stdio.h>

// int main(){
// 	char phone[20];
// 	scanf("%s",phone);

// 	//计算长度
// 	int length = 0;
// 	while (phone[length] != '\0') 
// 	{
// 		length++;
// 	}

// 	//判断长度是否合法
// 	if(length != 11)
// 	{
// 		printf("长度不合法\n");
// 	}
// 	else
// 	{
// 		//判断每一位是否都是数字
// 		int theBool = 1;
// 		for(int i=0;i<length;i++)
// 		{
// 			if(phone[i]<'0'||phone[i]>'9')
// 			{
// 				printf("字符串中存在非数字字符\n");
// 				theBool = 0;
// 				break;
// 			}
// 		}
// 		if(theBool) 
// 		{
// 			//判断第1位是否合法
// 			if(phone[0] != '1')
// 			{
// 				printf("第1位不合法\n");
// 			}
// 			else
// 			{
// 				//判断第2位是否合法
// 				if(phone[1] != '3' && phone[1] != '4' && phone[1] != '5' && phone[1] != '7' && phone[1] != '8')
// 				{
// 					printf("第2位不合法\n");
// 				}
// 			}
// 		}
// 	}

// 	return 0;  
// }


// //? 喂，这道题不是要循环输入吗？？？？？？