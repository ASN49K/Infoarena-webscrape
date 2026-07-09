/*
    Keep It Simple!
*/

#include<stdio.h>

int euclid(int a,int b)
{
   if(!b) return a;
   return euclid(b,a%b);
}

int main()
{
    int T,x,y;

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&T);

    for(int i=1;i<=T;i++)
       {
          scanf("%d%d",&x,&y);
          printf("%d\n",euclid(x,y));
       }
    return 0;
}
