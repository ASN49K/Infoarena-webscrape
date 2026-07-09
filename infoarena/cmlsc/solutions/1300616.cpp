#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    ifstream si;
    si.open("cmlsc.in");
    ofstream so;
    so.open("cmlsc.out");
    int n,m;
    si>>n>>m;
    int a[n];
    int b[m];
    int i;
    for(i=0;i<n;++i)
        si>>a[i];
    for(i=0;i<m;++i)
        si>>b[i];
    int v[n+1][m+1],j;
    for(i=0;i<=n;++i)
        v[i][0]=0;
    for(i=0;i<=m;++i)
        v[0][i]=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(a[i-1]==b[j-1])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    int s[v[n][m]],cont=v[n][m]-1;
    for(i=n,j=m;i>0;)
    {
        if(a[i-1]==b[j-1])
        {
            s[cont]=a[i-1];
            --cont;
            --i;
            --j;
        }
        else
        {
            if(v[i][j-1]>v[i-1][j])
                --j;
            else
                --i;
        }
    }
    so<<v[n][m]<<'\n';
    for(i=0;i<v[n][m];++i)
        so<<s[i]<<' ';
    so<<'\n';
}
