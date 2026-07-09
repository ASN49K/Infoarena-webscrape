#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1030],b[1030],mat[1030][1030],v[1025];
int main()
{
    int i,j,n,m,cmlsc=0;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;++i) scanf("%d",&b[i]);
    for(i=1;i<=m;++i)
        for(j=1;j<=n;j++)
            if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    for(i=m,j=n;i;)
        if(a[i]==b[j])
            {v[++cmlsc]=a[i];i--;j--;}
        else if(mat[i][j-1]<mat[i-1][j]) i--;
        else j--;
    printf("%d\n",cmlsc);
    for(;cmlsc;cmlsc--) printf("%d ",v[cmlsc]);
    fclose(stdin);fclose(stdout);
    return 0;
}
