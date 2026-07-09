#include<cstdio>
#include<cstring>
int f[35];
using namespace std;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int n,i,j,m,x,nr,k,ok;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        memset(f,0,sizeof(f));
        scanf("%d",&m);
        for(j=1;j<=m;++j)
        {
            scanf("%d",&x);
            nr=-1;
            while(x!=0)
            {
                f[++nr]+=(x%2);
                x/=2;
            }
        }
        ok=0;
        for(k=0;k<=30;++k)
        {
            if(f[k]%2)
            {
                ok=1;
                break;
            }
        }
        if(ok)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
