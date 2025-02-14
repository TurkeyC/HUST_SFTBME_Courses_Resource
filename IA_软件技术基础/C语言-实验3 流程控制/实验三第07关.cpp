#include<stdio.h>
#include<math.h>

int main() {
    int i=0, n, price=0, last_price=0, max=0;
    scanf("%d", &n);

    do
    {
        scanf("%d", &price);
        if(abs(price-last_price) > max)
            max = abs(price-last_price);
        last_price = price;
        i++;
    } while (i<n);
    
    printf("%d\n", max);
    return 0;
}
