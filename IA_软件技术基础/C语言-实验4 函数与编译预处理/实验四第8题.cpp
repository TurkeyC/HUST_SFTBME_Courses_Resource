#include<stdio.h>
#include<math.h>

#define S ( ((a)+(b)+(c))/2 )
#define AREA ( sqrt( (S) * ((S)-(a)) * ((S)-(b)) * ((S)-(c)) ) )

int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    if(!(a+b<=c || a+c<=b || b+c<=a))
        printf("%.2f\n",AREA);

    return 0;
}