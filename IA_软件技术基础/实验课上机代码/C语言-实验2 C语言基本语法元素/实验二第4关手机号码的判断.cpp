//���ȺϷ�>ÿһλ��������>��1λ�Ϸ�>��2λ�Ϸ�
//1304567854 ���Ȳ��Ϸ�
//170*56785-3 �ַ����д��ڷ������ַ�
//10234567543 ��2λ���Ϸ�
//76045678543 ��1λ���Ϸ�

#include<stdio.h>

int main(){
	char phone[20];

	while(scanf("%s",phone) != EOF)//����û�������Ctrl+Z�������ѭ��
	{	
		//���㳤��
		int length = 0;
		while (phone[length] != '\0') 
		{
			length++;
		}

		//�жϳ����Ƿ�Ϸ�
		if(length != 11)
		{
			printf("���Ȳ��Ϸ�\n");
			continue;
		}
		
		//�ж�ÿһλ�Ƿ�������
		bool theBool = true;
		for(int i=0;i<length;i++)
		{
			if(phone[i]<'0'||phone[i]>'9')
			{
				printf("�ַ����д��ڷ������ַ�\n");
				theBool = false;
				break;
			}
		}
		if(!theBool) continue;

		//�жϵ�1λ�Ƿ�Ϸ�
		if(phone[0] != '1')
		{
			printf("��1λ���Ϸ�\n");
			continue;
		}

		//�жϵ�2λ�Ƿ�Ϸ�
		if(phone[1] != '3' && phone[1] != '4' && phone[1] != '5' && phone[1] != '7' && phone[1] != '8')
		{
			printf("��2λ���Ϸ�\n");
			continue;
		}

	}
	return 0;  
}




// #include<stdio.h>

// int main(){
// 	char phone[20];
// 	scanf("%s",phone);

// 	//���㳤��
// 	int length = 0;
// 	while (phone[length] != '\0') 
// 	{
// 		length++;
// 	}

// 	//�жϳ����Ƿ�Ϸ�
// 	if(length != 11)
// 	{
// 		printf("���Ȳ��Ϸ�\n");
// 	}
// 	else
// 	{
// 		//�ж�ÿһλ�Ƿ�������
// 		int theBool = 1;
// 		for(int i=0;i<length;i++)
// 		{
// 			if(phone[i]<'0'||phone[i]>'9')
// 			{
// 				printf("�ַ����д��ڷ������ַ�\n");
// 				theBool = 0;
// 				break;
// 			}
// 		}
// 		if(theBool) 
// 		{
// 			//�жϵ�1λ�Ƿ�Ϸ�
// 			if(phone[0] != '1')
// 			{
// 				printf("��1λ���Ϸ�\n");
// 			}
// 			else
// 			{
// 				//�жϵ�2λ�Ƿ�Ϸ�
// 				if(phone[1] != '3' && phone[1] != '4' && phone[1] != '5' && phone[1] != '7' && phone[1] != '8')
// 				{
// 					printf("��2λ���Ϸ�\n");
// 				}
// 			}
// 		}
// 	}

// 	return 0;  
// }


// //? ι������ⲻ��Ҫѭ�������𣿣���������