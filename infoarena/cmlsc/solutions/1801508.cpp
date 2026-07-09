#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],L[1025][1025],v[1025],q;
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;++i)
        fin>>a[i];
    for(int i=1;i<=m;++i)
        fin>>b[i];
}
void partea1()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]==b[j]) L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
}
void partea2()
{
    fout<<L[n][m]<<'\n';
    int i=n, j=m;
    q=L[i][j];
    while(q>0)
    {
        if(a[i]==b[j])
        {
            v[q--]=a[i];
            i--;j--;
        }
        else
            if(L[i][j-1]>L[i-1][j]) j--;
            else   i--;
    }
    for(int i=1;i<=L[n][m];++i)
        fout<<v[i]<<" ";
}
int main()
{
    citire();
    partea1();
    partea2();
}
