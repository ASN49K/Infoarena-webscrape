#include <iostream>
#include <cmath>
using namespace std;
int c[100][100],a[100],b[100],x,y,m,n,i,j;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(j=1;j<=m;j++)
    cin>>b[j];
    for(j=1;i<=m;i++)
    if(a[1]==b[j])
    c[1][j]=1;
    for(i=1;i<=n;i++)
    if(b[1]==a[i])
    c[i][1]=1;
    for(i=2;i<=n;i++)
    for(j=2;j<=m;j++)
    if(a[i]==b[j])
    c[i][j]=1+c[i-1][j-1];
    else
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    cout<<c[n][m];
    x=n;
    y=m;
    while(x>0 && y>0){
    if(a[x]==b[y]){
    cout<<a[x];
    x--;y--;
    }
    if(c[x-1][y]>c[x][y-1])
    x--;
    else
    y--;
    }
    return 0;
}
