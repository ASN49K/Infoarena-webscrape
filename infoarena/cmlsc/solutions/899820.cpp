#include<cstdio>
#include<deque>
#include<algorithm>
#define INF 1026

using namespace std;

int a[INF],b[INF],din[INF][INF],n,m,i,j;
deque<int> ras;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]);

    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        if(a[i]==b[j])din[i][j]=din[i-1][j-1]+1;
        else din[i][j]=max(din[i-1][j],din[i][j-1]);

    for(i=m, j=n;i>0,j>0;)
    {
        if(a[i]==b[j]){ras.push_front(a[i]);--i,--j;}
        else if(din[i][j-1]<din[i-1][j])--i;
        else --j;
    }
    printf("%d\n",ras.size());
    for(int i=0;i<ras.size();++i)printf("%d ",ras[i]);
    return 0;
}
