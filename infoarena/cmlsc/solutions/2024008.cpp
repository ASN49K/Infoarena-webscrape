#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[1025], b[1025], c[1025][1025], d[1025], k;

void citireDate()
{
    f>>m>>n;
    for(int i=1;i<=m;i++) f>>a[i];
    for(int i=1;i<=n;i++) f>>b[i];
}

void formareMatriceDrum()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1] + 1;
            else c[i][j]=max(c[i][j-1], c[i-1][j]);

}

void interpretareDrum()
{
    int i=m, j=n;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j] > c[i][j-1]) i--;
             else j--;
    }
}

void afisareDate()
{
    g<<c[m][n]<<'\n';
    for(int i=k;i>=1;i--) g<<d[i]<<" ";
}

int main()
{
    citireDate();
    formareMatriceDrum();
    interpretareDrum();
    afisareDate();
    return 0;
}
