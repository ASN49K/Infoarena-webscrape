#include<cstdio>
using namespace std;
int T,N,i,S,a;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&T);
    for(;T;--T)
    {
        scanf("%d",&N);
        S=0;
        for(i=1;i<=N;i++)
        {
            scanf("%d",&a);
            S^=a;
        }
        if(S) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
