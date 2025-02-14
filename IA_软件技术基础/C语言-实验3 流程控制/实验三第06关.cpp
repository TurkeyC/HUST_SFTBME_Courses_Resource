#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
	//遍历10^n-1到10^n
	for(int num=((int)pow(10, n-1)); num<((int)pow(10, n)) ; num++)
    {
        //判断n位数平方的末尾n位和原数是否相同
        if(num == (((int)pow(num, 2)) % ((int)pow(10, n))))
            printf("%d\n",num);
    }
    return 0;
}