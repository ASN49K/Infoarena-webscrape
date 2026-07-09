#include <iostream>

using namespace std;

int main()
{
    int a[100],b[100], s[100][100],i,j,n,m;
    cin>>n>>m;
    for (i=1;i<=n;i++) cin>>a[i];
    for (j=1;j<=m;j++) cin>> b[j];
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    if(a[i]==b[j]){
    s[i][j]== s[i-1][j-1]+1;
    cout<<a[i]<<"  ";}
    else
    s[i][j]==max (s[i+1][j],s[i][j+1]);
    return 0;

}
