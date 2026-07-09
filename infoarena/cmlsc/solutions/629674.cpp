#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector<int>sol;
    int a[100],b[100],s[100][100],i,j,m,n,max;
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++) scanf("%d",&a[i]);
for(i=1;i<=m;i++) scanf("%d",&b[i]);
for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
    {
        if(a[i]==b[j]) s[i][j]=s[i][j-1]+1;
        else if(s[i][j-1]>s[i-1][j]) s[i][j]=s[i][j-1];
             else s[i][j]=s[i-1][j];
    }
}
max=s[n][m];
printf("%d\n",max); i=1;j=1;
i=n;j=m;
while(i>0&&j>0)
{
    if(a[i]==b[j])
    {
        sol.push_back(a[i]);
        i--;j--;
    }
    else if(s[i-1][j]<s[i][j-1]) j--;
    else i--;
}
for(i=max-1;i>=0;i--) printf("%d ",sol[i]);
return 0;
}
//1 7 3 9 8
//1 8 5 7 9
