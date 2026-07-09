#include <cstdio>
#include<algorithm>
#define f(i, a) for (i = 1; i <= a; i++)
#define oo 1030
using namespace std;
int M,N,k=0,x[oo],y[oo],ans[oo],l[oo][oo],i,j;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d",&M,&N);
    f(i,M)
        scanf("%d",&x[i]);
    f(i,N)
        scanf("%d",&y[i]);

    f(i,M)
        f(j,N)
            if(x[i]==y[j])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);

    i=M,j=N;
    while(i)
        if(x[i]==y[j])
            ans[++k]=x[i],--i,--j;
        else
            if(l[i][j-1]>l[i-1][j])
                --j;
            else
                --i;

    printf("%d\n",k);
    for(; k; --k)
        printf("%d ", ans[k]);
}
