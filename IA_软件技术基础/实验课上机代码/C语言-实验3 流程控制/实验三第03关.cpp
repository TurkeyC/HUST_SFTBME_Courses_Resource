#include<stdio.h>
int main()
{
	int i,x,k,flag=0;
	printf("�������жϺ���,���������1������,��Ctrl+Z����\n");
	while(scanf("%d",&x)!=EOF){
        i=2;
		do
        {
            if(!(x%i)){
				flag=1;
			}
            i++;
        }
        while(i<=x-1 && !flag);

		if(flag==1) printf("%d�Ǻ���",x);
		else printf("%d���Ǻ���",x); 
        flag=0;
	}
	return 0;
}
