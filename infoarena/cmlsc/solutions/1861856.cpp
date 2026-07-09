#include <cstdio>
using namespace std;
int n, v[10000], l[10000], maxt, pm;

void afis(int k,int m)
{
    if(!m)
        return;
    int i=k-1;
    while(l[i]!=m-1||v[k]<v[i])
        i--;
    afis(i,m-1);
    printf("%d ",i+1);
}
int main()
{
    freopen("sclm.in","r",stdin);
    freopen("sclm.out","w",stdout);
    int max,maxim=0,n,i,j,pi=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    l[1]=1;
    for(i=2;i<=n;i++)
    {
        max=0;
        for(j=1;j<i;j++)
        {
            if(v[i]>=v[j]&&l[j]>max)
                max=l[j];
        }
        l[i]=max+1;
        if(l[i]>maxim)
        {
            maxim=l[i];
            pi=i;
        }
    }

    printf("%d\n",maxim);
    afis(pi,maxim);
}
