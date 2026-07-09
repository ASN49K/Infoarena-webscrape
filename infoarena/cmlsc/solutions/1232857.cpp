#include <iostream>
#include <fstream>
using namespace std;
#define MAX 1026
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[MAX],b[MAX];
int c[MAX][MAX], d[MAX];
int main()
{
    int n,m;
    fin >> n >> m;
    for(int i = 1; i<=n; i++)
        fin >> a[i];
    for(int i = 1; i<=m; i++)
        fin >> b[i];
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {
            if(a[i]==b[j])
                c[i][j] = c[i-1][j-1]+1;
            else
                c[i][j] = max(c[i-1][j],c[i][j-1]);
        }
    fout << c[n][m] << "\n";

    int i = n;
    int j = m;
    int dr = 0;
    while(c[i][j])
    {
        while(c[i][j]==c[i-1][j])
            i--;
        while(c[i][j]==c[i][j-1])
            j--;
        d[++dr] = a[i];
        i--;j--;

    }
    for(int i = dr; i>=1; i--)
        fout << d[i] << " ";

    return 0;
}
