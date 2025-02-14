// #include<stdio.h>
// //给定n个整数表示一个商店连续n天的销售量，计算出这些天总共有多少个折点。
// int main(){
// 	int n, point = 0;
// 	scanf("%d", &n);
	
// 	int sale[n];
// 	for(int i = 0; i <= n - 1; i++)
// 	{
// 		scanf("%d", &sale[i]);
// 	}

// 	if(n >= 3)
// 	{
// 		for(int i = 1; i <= n - 2; i++)
// 			{
// 				if(sale[i] > sale[i - 1] && sale[i] > sale[i + 1] || sale[i] < sale[i - 1] && sale[i] < sale[i + 1])
// 				{
// 					point++;
// 				}
				
// 			}
// 	}
	
// 	printf("%d", point);

// 	return 0;  
// }


#include<stdio.h>
int main()
{
    int n, i, b, m, sum;
    scanf("%d",&n);
    int a[114514];
    for(i=0;i<n;i++) 
    {
        scanf("%d",&a[114514]);
    }
    if(n>=3){
        for(b=1;b!=n;b++){
            if(a[b]>a[b-1]&&a[b]>a[b+1] || a[b]<a[b-1]&&a[b]<a[b+1])
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}