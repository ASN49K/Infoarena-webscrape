#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t,i,x,y,n,j;
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d",&n);
        scanf("%d",&x);
        for (j=1;j<n;j++){scanf("%d",&y);
                          x=x^y;}
        if(x!=0)printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
