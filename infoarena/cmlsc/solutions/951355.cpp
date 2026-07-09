#include <cstdio>
#define N 1025
#include<algorithm>
using namespace std;
int n,m,i,j,k,a[N],b[N],c[N],d[N][N];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);//lungimile sirurilor
    for(i=1;i<=n;i++)scanf("%d",&a[i]);//primul sir
    for(i=1;i<=m;i++)scanf("%d",&b[i]);//al doilea sir
    // d[i][j]= cel mai lung subsir comun daca
    //pentru a luam pozitiile pana la pozitia i
    //pentru b luam pozitiile pana la pozitia j
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    printf("%d\n",d[n][m]);
    for(i=n,j=m;d[i][j];)
    {
        if(a[i]==b[j]){c[++k]=a[i];i--;j--;}
        else if(d[i][j-1]>=d[i-1][j])j--;
        else i--;
    }
    for(i=k;i>=1;i--)
        printf("%d ",c[i]);
    return 0;
}
