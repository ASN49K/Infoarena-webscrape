#include<stdio.h>
 
int T , n , c;
char ch;
 
int main()
{
    freopen("nim.in" , "r" , stdin);
    freopen("nim.out" , "w" , stdout);
    scanf("%d" , &T);
    for( ; T > 0 ; -- T)
    {
        scanf("%d " , &n);
        int a = 0;
        for(int i = 1 ; i <= n ; ++ i)
        {
            scanf("%d " , &c);
            a ^= c;
        }
        if(a == 0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}