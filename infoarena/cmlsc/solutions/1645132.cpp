#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v[1025], a[1025], b[1025], c[1025][1025];
void citire()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
}
void cmlsc()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=c[i][j-1]+1;
            }
            else
            {
                c[i][j]=max(c[i-1][j], c[i][j-1]);
            }
        }
    }
}
void afisare()
{
    int t=c[n][m];
    while(c[n][m]!=0)
    {
        if(c[n][m]>c[n-1][m]&&c[n][m]>c[n][m-1])
        {
            v[c[n][m]]=a[n];
            n--;
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
    for(int i=1;i<=t;i++)
    {
        fout<<v[i]<<' ';
    }
}
int main()
{
    citire();
    cmlsc();
    afisare();
    fin.close();
    fout.close();
    return 0;
}
