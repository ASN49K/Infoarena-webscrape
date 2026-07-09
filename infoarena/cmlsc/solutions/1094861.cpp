#include <iostream>
#include <fstream>

using namespace std;

int a[101], b[101], aux[101][101], c[101];
int n, m, dim;

void Citire()
{
    ifstream fin("cmlsc.in");
    fin>> n >> m;
    for(int i = 1; i <= n; i++)
        fin>>a[i];
    for(int i = 1; i <= m; i++)
        fin>>b[i];
}

void Rezolvare()
{
    int i, j;
    for(i = 0; i <= n; i++) aux[i][0] = 0;
    for(i = 0; i <= m; i++) aux[0][i] = 0;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j]) aux[i][j] = 1 + aux[i-1][j-1];
            else aux[i][j] = max(aux[i-1][j], aux[i][j-1]);
}

int ReconstruireVector(int i, int j)
{
    if( i>0 || j>0)
    {
        if(a[i] == b[j])
        {
            c[++dim] = a[i];
            return ReconstruireVector(i-1, j-1);
        }
        else
            if(aux[i-1][j] > aux[i][j-1]) return ReconstruireVector(i-1,j);
            else return ReconstruireVector(i,j-1);
    }
    return 0;
}

int main()
{
    Citire();
    Rezolvare();
    ReconstruireVector(n,m);
    ofstream fout("cmlsc.out");
    for(int i = dim-1; i>0 ; i--)
        fout<<c[i];
    fout.close();
    return 0;
}
