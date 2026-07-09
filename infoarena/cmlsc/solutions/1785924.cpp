#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define MAXLEN 1025

int n,m,a[MAXLEN],b[MAXLEN],c[MAXLEN][MAXLEN];

void citire()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=m;i++)
        in>>b[i];
}

void dp()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else c[i][j]=c[i][j-1]>c[i-1][j]?c[i][j-1]:c[i-1][j];
        }
}

void gasire_sol()
{
    vector<int>d;
    int len=0;
    for (int i=n , j = m; i; )
    {
        if (a[i] == b[j])
        {
            d.push_back(a[i]);
            len++;
            i--;
            j--;
        }
        else if (c[i-1][j] < c[i][j-1])
            j--;
        else
            i--;
    }
    for(int i=len-1;i>=0;i--)
        out<<d[i]<<' ';
}

int main()
{
    citire();
    dp();
    out<<c[n][m]<<'\n';
    gasire_sol();
    return 0;
}
