#include <cstdio>
#define max_l 1024
using namespace std;
int n,m,a[max_l],b[max_l];
int lcs[max_l][max_l];
int s[max_l],bst;
int max(int x,int y){
if(x>y)return x;
return y;
}
int main(void){
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
int i=1,j;
for(i=1;i<=m;i++)scanf("%d",&a[i]);
for(i=1;i<=n;i++)scanf("%d",&b[i]);
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
lcs[i][j]=lcs[i-1][j-1]+1;
else          
lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
for(i=m;j=n;i; ){
if(a[i]==b[j]){
s[++bst]=a[i];
--i;--j;
}
else 
if(lcs[i-1][j]>lcs[i][j-1])
i--;
else
j--;
}
printf("%d\n",bst);
for(i=bst;i>0;i--)
printf("%d ",s[i]);
}