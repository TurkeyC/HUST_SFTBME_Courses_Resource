// ? 目测已完成

#include<stdio.h>

unsigned long long sum_fac(int n);

int main()
{
	int k;
	for(k=1; k<=20; k++)
		printf("k=%d the sum is %llu\n",k,sum_fac(k));
	return 0;
}

unsigned long long sum_fac(int n)
{
	unsigned long long s=0, fac=1;
	int i;
	for(i=1;i<=n;i++) 
	{
		fac*=i;
		s+=fac;
	}
	return s;
}

