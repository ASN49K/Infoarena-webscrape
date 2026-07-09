#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define mp make_pair
#define pb push_back
int T,x,y;

int euclid(int a,int b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",euclid(x,y));
    }
    return 0;
}
