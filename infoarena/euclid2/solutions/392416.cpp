#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int cmmdc(int a,int b)
{
    if (!b) return a;
    else return cmmdc(b,a%b);
}

int main()
{int t,i,x,y;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d %d",&x,&y);
    
        printf("%d\n",cmmdc(x,y));
    }
return 0;
}
