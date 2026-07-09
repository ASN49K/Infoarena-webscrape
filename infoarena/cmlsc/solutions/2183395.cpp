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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) lg[i][j]=lg[i-1][j-1]+1;
            else lg[i][j]=max(lg[i][j-1],lg[i-1][j]);
        }
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
        else if(i-1>=1&&lg[i][j]==lg[i-1][j]) i--;
        else j--;
    }
    out<<k<<"\n";
    for(int i=k;i>=1;i--) out<<c[i]<<" ";
    return 0;
}
