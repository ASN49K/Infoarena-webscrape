#include <iostream>
#include <fstream>
#define MAX 1040

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int a[MAX],b[MAX],c[MAX];
int v[MAX][MAX];

void solutie(int n, int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i] == b[j]) v[i][j] = 1 + v[i-1][j-1];
            else
                v[i][j] = max(v[i-1][j],v[i][j-1]);
        }
    }
    g<<v[n][m]<<"\n";

    int i=n;
    int j=m;

    int sol[MAX];
    int index = 0;

    while(i!=0 && j!=0)
    {
        if(a[i] == b[j])
        {
            sol[++index] = a[i];
            i--;
            j--;
        }
        else
            if(v[i-1][j]>v[i][j-1]) i --;
            else j--;
    }
    for(int i = index;i>=1;i--)  g<<sol[i]<<" ";
}

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];

    solutie(n,m);
    g.close();

    return 0;
}
