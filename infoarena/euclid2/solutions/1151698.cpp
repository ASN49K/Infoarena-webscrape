#include <iostream>
#include <cstdio>
using namespace std;

int N,A,B;

int CMMDC(int x,int y)
{
    if(!y)
        return x;
    return CMMDC(y,x%y);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d\n",&N);
    for(int i=0;i<N;++i)
    {
        scanf("%d %d",&A,&B);
        printf("%d\n",CMMDC(A,B));
    }
    return 0;
}
