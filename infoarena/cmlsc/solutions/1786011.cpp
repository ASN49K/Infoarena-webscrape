#include <iostream>
#include <fstream>

using namespace std;

int c[1025][1025], d[1025];

void Citire(int b[1025], int a[1025], int &n, int &m)
{
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];
}

void Construire( int a[1025], int b[1025], int n, int m)
{
    int k=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                c[i][j]=1+c[i-1][j-1];
                d[k++]=a[i];
            }
            else c[i][j]=max(c[i-1][j], c[i][j-1]);
}

int main()
{
    int a[1025]={0}, b[1025]={0}, n, m;
    Citire(b, a, n, m);
    Construire(a, b, n, m);

    ofstream fout("cmlsc.out");

    fout<<c[n][m]<<endl;

    for(int i=0; i<c[n][m]; i++)
        fout<<d[i]<<" ";
    return 0;
}
