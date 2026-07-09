#include <iostream>
#include <stdio.h>

using namespace std;
int euclid(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    int t,x,y;

    freopen("euclid.in","r",stdin);
    freopen("euclid.out","w",stdout);

     scanf("%d",&t);

     for(int i=1;i<=t;i++)
     {
         scanf("%d%d",&x,&y);
         printf("%d\n",euclid(x,y));
     }
}
