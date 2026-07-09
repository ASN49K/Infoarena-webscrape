#include<cstdio>

using namespace std;

int T,A,B;

int cmmdc(int x,int y)
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
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&T);

    for(; T; --T)
    {
        scanf("%d%d",&A,&B);
        printf("%d\n",cmmdc(A,B));
    }

    return 0;
}
