#include<cstdio>
using namespace std;
int i,j,k,n,m,d[1026][1026],a[1026],b[1026],sir[1026];
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=n;
    j=m;
    while(i!=0)
    {
        if(a[i]==b[j])
        {
            k++;
            sir[k]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])j--;
        else i--;
    }
    printf("%d\n",d[n][m]);
    for(i=k;i>=1;i--)
        printf("%d ",sir[i]);
    return 0;
}
