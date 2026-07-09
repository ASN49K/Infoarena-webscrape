#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int sz = 1024;
int solsz;
int sol[sz + 5];
int n,m;
short a[sz + 5];
short b[sz + 5];
int d[sz + 5][sz + 5];



int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++){fin>>a[i];d[i][0]=-100;}
    for(int i=1;i<=m;i++){fin>>b[i];d[0][i]=-100;}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=(a[i]==b[j]) ? (d[i-1][j-1]+1) : (max(d[i-1][j],d[i][j-1]));
    int x = n;
    int y = m;
    while(x>=1 || y>=1)
    {
        if(a[x]==b[y])
            sol[++solsz] = a[x],x--,y--;
        else
            (d[x-1][y] > d[x][y-1]) ? x-- : y--;
    }
    fout<<solsz<<'\n';
    for(int i = solsz;i>=1;i--)
        fout<<sol[i]<<' ';

}


