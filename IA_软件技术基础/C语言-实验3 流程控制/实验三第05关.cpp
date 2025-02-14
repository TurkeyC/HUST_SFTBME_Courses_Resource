#include<stdio.h>
#include<math.h>
int main()
{
    int x, tax;
    scanf("%d", &x);

    switch (x / 1000) 
    {
        case 0:
            tax = 0;
            break;
        case 1:
            tax = (int)((x-1000) * 0.05);
            break;
        case 2:
            tax = (int)((x-2000) * 0.10)+50;
            break;
        case 3:
            tax = (int)((x-3000) * 0.15)+50+100;
            break;
        case 4:
            tax = (int)((x-4000) * 0.20)+50+100+150;
            break;
        default:
            tax = (int)((x-5000) * 0.25)+50+100+150+200;
            break;
    }


    printf("%d\n", tax);

	return 0;
}