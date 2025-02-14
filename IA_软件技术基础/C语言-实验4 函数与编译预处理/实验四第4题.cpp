// // ! 目测未完成

// #include<stdio.h>

// unsigned long long sum_fac(int n);

// int main()
// {
//     int k;
//     for(k=1; k<=20; k++)
//         printf("k=%d the sum is %llu\n",k,sum_fac(k));
//     return 0;
// }

// unsigned long long sum_fac(int n)
// {
//     static unsigned long long s[21]={0}, fac=1;
//     int i;

//     if(s[n]!=0)
//         return s[n];
//     else
//         return s[n]=sum_fac(n-1)+s[n-1];



//     // for(i=1;i<=n;i++)
//     // {
//     //     fac*=i;
//     //     s+=fac;
//     // }
//     return 0;
// }



//
// Created by Cao_Turkey_Su on 24-10-31.
//

// ? 目测已完成

#include<stdio.h>

unsigned long long sum_fac(int n);

int main()
{
    int k;
    for(k=1; k<=20; k++)
        printf("k=%d the sum is %llu\n",k,sum_fac(k,1));
    return 0;
}

// unsigned long long sum_fac(int n)
// {
//     static unsigned long long s[21]={0}, fac=1;
//     int i;
//
//     if(s[n]!=0)
//         return s[n];
//     else
//         fac*=n;
//     s[n]=sum_fac(n-1)+s[n-1];
//
//     return n * sum_fac(n - 1);
//
//
//
//     // for(i=1;i<=n;i++)
//     // {
//     //     fac*=i;
//     //     s+=fac;
//     // }
//     return 0;
// }
//
unsigned long long sum_fac(int n, int count)
{
    if (n == 1)
        return 1;
    else
    {

        long long current_factorial = n * sum_fac(n - 1, n - 1);
        if (count == 1) {
            return current_factorial;
        } else {
            return current_factorial + sum_fac(n - 1, 1);
        }



        // unsigned long long current_factorial = n * sum_fac(n - 1);
        //
        // return current_factorial + sum_fac(n - 1);

    }
}




// //
// // Created by Cao_Turkey_Su on 24-10-31.
// //

// // ? 目测已完成

// #include<stdio.h>

// unsigned long long sum_fac(int n, int count);

// int main()
// {
//     int k;
//     for(k=1; k<=20; k++)
//         printf("k=%d the sum is %llu\n",k,sum_fac(k,1));
//     return 0;
// }

// // unsigned long long sum_fac(int n)
// // {
// //     static unsigned long long s[21]={0}, fac=1;
// //     int i;
// //
// //     if(s[n]!=0)
// //         return s[n];
// //     else
// //         fac*=n;
// //     s[n]=sum_fac(n-1)+s[n-1];
// //
// //     return n * sum_fac(n - 1);
// //
// //
// //
// //     // for(i=1;i<=n;i++)
// //     // {
// //     //     fac*=i;
// //     //     s+=fac;
// //     // }
// //     return 0;
// // }
// //
// unsigned long long sum_fac(int n, int count)
// {
//     if (n == 1)
//         return 1;
//     else
//     {

//         long long current_factorial = n * sum_fac(n - 1, n - 1);
//         if (count == 1) {
//             return current_factorial;
//         } else {
//             return current_factorial + sum_fac(n - 1, 1);
//         }



//         // unsigned long long current_factorial = n * sum_fac(n - 1);
//         //
//         // return current_factorial + sum_fac(n - 1);

//     }
// }

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
    static unsigned long long f[21] = {0,1};
    if (n==1)
        return 1;
    else
        {
        f[n] = f[n-1]*n;
        return sum_fac(n-1)+f[n];
        }
}
