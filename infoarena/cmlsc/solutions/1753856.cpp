#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,a[1026],b[1026],c[1026][1026],n,m;
int drum(int i,int j){
if(i>0 && j>0){
if(a[i]==b[j]){
drum(i-1,j-1);
printf("%d ",a[i]);
}
else if(c[i-1][j]>c[i][j-1])drum(i-1,j);
else drum(i,j-1);
}
}
int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d %d",&n,&m);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<=m;i++)
    scanf("%d",&b[i]);
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(a[i]==b[j])c[i][j]=1+c[i-1][j-1];
else c[i][j]=max(c[i-1][j],c[i][j-1]);
printf("%d\n",c[n][m]);
drum(n,m);


    return 0;
}
