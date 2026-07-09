#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m;
short v1[1025],v2[1025];
short sol[1025],k;
short a[1025][1025];

void citire()
{
    int i;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>v1[i];
    for(i=1;i<=n;i++)
        in>>v2[i];
}

void rezolvare ()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i][j-1],a[i-1][j]);
        }
}

void afisare()
{
    int i=m,j=n;
    while(a[i][j])
    {
        if(v1[i]==v2[j])
            sol[++k]=v1[i],i--,j--;
        else if(a[i][j-1]>a[i-1][j])
            j--;
        else
            i--;
    }
    reverse(sol+1,sol+k+1);
    out<<a[m][n]<<'\n';
    for(i=1;i<=k;i++)
        out<<sol[i]<<' ';
}

int main()
{
    citire();
    rezolvare();
    afisare();
    return 0;
}
