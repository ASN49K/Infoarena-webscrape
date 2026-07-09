#include<iostream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
int n,m,a[100],b[100],s[100][100];
for(i=1;i<=n;i++)cout<<a[i];
for(j=1;j<=m;j++)cout<<b[j];
for (int i=1;i<=n,i++)
for (int j=1;j<=m,j++)
if(a[i]=b[j])
{
    s[i][j]=s[i-1][j=1]+1;
    cout<<[i]<<'';
    else s[i][j]=max(s[i-1][j],s[i][j-1])
    cout<<'/n'<<s[n][m];
    return 0;
}

