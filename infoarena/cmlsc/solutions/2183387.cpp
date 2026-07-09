#include"bits/stdc++.h"
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1025],b[1025],lg[1025][1025],k,i,j,c[1025];
unsigned long long s;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++) in>>a[i];
    for(int i=1;i<=m;i++) in>>b[i];
    lg[1][1]=(a[1]==b[1])?1:0;
    for(int i=2;i<=n;i++) lg[i][1]=(a[i]==b[1])?1:lg[i-1][1];
    for(int i=2;i<=m;i++) lg[1][i]=(a[1]==b[i])?1:lg[1][i-1];
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++) lg[i][j]=max((a[i]==b[j])?lg[i-1][j-1]+1:0,max(lg[i-1][j],lg[i][j-1]));
    }
    i=n;
    j=m;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
            i--;
            j--;
        }
        else if(i-1&&lg[i][j]==lg[i-1][j]) i--;
        else j--;
    }
    out<<k<<"\n";
    for(int i=k;i>=1;i--) out<<c[i]<<" ";
    return 0;
}
