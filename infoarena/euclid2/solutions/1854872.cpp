#include <stdio.h>
 
int nr, a, b;

int euclid(int a,int b)
{
    while(b!=0)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);
   scanf("%d", &nr);
   for(int i=nr;i>0;i--)
   {
        scanf("%d %d", &a, &b);
        printf("%d\n", euclid(a, a));
   }
}