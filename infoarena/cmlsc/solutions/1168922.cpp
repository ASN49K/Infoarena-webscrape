#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1028],b[1028],d[1028][1028],s[1028];
int main()
{
    int i,j,m,n,k;
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    k=0;
    i=m;j=n;
    while(i)
    {
        if(a[i]==b[j])
            s[++k]=a[i],i--,j--;
        else if(d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    fout<<d[m][n]<<'\n';
    for(i=k;i;i--)
        fout<<s[i]<<' ';
    fout<<'\n';
    return 0;
}
