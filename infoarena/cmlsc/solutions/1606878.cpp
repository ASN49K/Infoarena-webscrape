#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025], b[1025], c[1025][1025], n, m;
int main()
{
    fin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        fin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(b[i]==a[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
                c[i][j]=max(c[i-1][j], c[i][j-1]);
        }
    }
    /*
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fout<<c[i][j]<<' ';
        }
        fout<<'\n';
    }
    */
    int v[1025], k=c[n][m];
    int aux=k;
    fout<<c[n][m]<<'\n';
    while(c[n][m]!=0)
    {
        if(c[n-1][m]==c[n][m-1]&&c[n][m]!=c[n-1][m-1])
        {
            v[k--]=b[n];
            n--;
            m--;
        }
        else if(c[n-1][m]>c[n][m-1])
        {
            n--;
        }
        else
        {
            m--;
        }
    }
    k=1;
    for(int i=1;i<=aux;i++)
    {
        fout<<v[i]<<' ';
    }
    fin.close();
    fout.close();
    return 0;
}
