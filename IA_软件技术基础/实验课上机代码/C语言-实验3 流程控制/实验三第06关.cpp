#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
	//����10^n-1��10^n
	for(int num=((int)pow(10, n-1)); num<((int)pow(10, n)) ; num++)
    {
        //�ж�nλ��ƽ����ĩβnλ��ԭ���Ƿ���ͬ
        if(num == (((int)pow(num, 2)) % ((int)pow(10, n))))
            printf("%d\n",num);
    }
    return 0;
}