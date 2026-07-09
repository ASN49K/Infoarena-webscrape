#include<stdio.h>


int main()
{
    int a, b, div = 0;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);

    if(a > b)
    {
        for(int i = b/2; i >= 1; i--)
        {
           if((a % i == 0) && (b % i == 0))
           {
               div = i;
               break;
           }
        }
    }
    else
    {
       for(int i = a/2; i >= 1; i--)
        {
           if((a % i == 0) && (b % i == 0))
           {
               div = i;
               break;
           }
        }
    }
    printf("cmmdc = %d", div);

return 0;
}
