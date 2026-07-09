#include <iostream>
#define N 1025
#include <cstdio>
#include <vector>
using namespace std;
int i,j,n,m,a[N],b[N],d[N][N];
vector <int> v;
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
        {
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    printf("%d\n",d[n][m]);
    for(i=n,j=m;d[i][j];)
    {
        if(a[i]==b[j]){ v.push_back(a[i]);i--;j--;}
        else if(d[i-1][j]>d[i][j-1]) i--;
        else j--;
    }
    for(vector<int>::reverse_iterator it = v.rbegin();it!=v.rend();it++)
        printf("%d ",*it);

    return 0;
}
