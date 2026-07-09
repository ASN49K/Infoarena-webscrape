#include <stdio.h>

int main()
{
    int N,M,t[257]={0},i,MAX=0,c,el,e,a;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(i=0;i<N+M;++i)
    {
        scanf("%d",&a);
        t[a]++;
    }
    for(i=0;i<257;++i)
    {
        c=0;
        e=i;
        while(t[i]==2)
        {
            ++i;
            ++c;
        }
        if(MAX<c)
        {
            MAX=c;
            el=e;
        }
    }
    printf("%d\n%d %d",MAX,el,el+MAX-1);
    return 0;
}
