#include<stdio.h>
#include<assert.h>
#include <math.h>
#define R

int integer_fraction(float x);

int main(void)
{
    double r,s=0.0;
    int s_integer=0;
    printf("Input a number: ");
    scanf("%lf",&r);

#ifdef R
    s=3.14159*r*r;
    printf("Area of round is: %f\n",s);
    s_integer=integer_fraction(s);
    assert((s-s_integer)<1);
    printf("The integer fraction of area is: %d\n",s_integer);
#endif
    return 0;
}

int integer_fraction(float x)
{
    int i=round(x);
    return i;
}