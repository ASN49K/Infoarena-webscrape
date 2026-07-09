#include <iostream>
#include <fstream>
#define nmax 1024
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n;
int a[nmax],b[nmax],d[nmax][nmax],sir[nmax],best;

void read()
{
    int i,j;
    fin>>m>>n;
    for(i=1;i<=m;++i) fin>>a[i];
    for(i=1;i<=n;++i) fin>>b[i];
}

void prec()
{
    int i,j;
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
}

void solve()
{
    int i,j;
    for(i=m,j=n;i>=1;)
        if(a[i]==b[j])
            {
             sir[++best]=a[i];
             i--;
             j--;
            }
         else
            if(d[i-1][j]<d[i][j-1]) j--;
            else i--;
     fout<<best<<"\n";
     for(i=best;i>=1;i--)
        fout<<sir[i]<<" ";
}


int main()
{
   read();
   prec();
   solve();
    return 0;
}
