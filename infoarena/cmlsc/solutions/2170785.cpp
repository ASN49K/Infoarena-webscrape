#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short N,M,a[1040],b[1040],i,j,m[1040][1040],nr,q[1024];

int main()
{
    fin>>N>>M;
    for(i=1;i<=N;i++)
        fin>>a[i];
    for(j=1;j<=M;j++)
        fin>>b[j];
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(a[i]==b[j])
            {
                m[i][j]=m[i-1][j-1]+1;
            }
            else
            {
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    fout<<m[N][M]<<'\n';
    nr=m[N][M];
    for(i=N;i>=1;i--)
    {
        for(j=M;j>=1;j--)
        {
            if(a[i]==b[j]&&m[i][j]==nr)
            {
                q[nr]=a[i];
                nr--;
            }
        }
    }
    for(i=1;i<=m[N][M];i++)
    {
        fout<<q[i]<<' ';
    }


}
