#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int lcs[1025][1025];
void afiseazaSir(int a[], int b[], int m, int n)
{
    if(lcs[m][n])
    {
        if(lcs[m][n] == max(lcs[m-1][n], lcs[m][n-1]))
        {
            if(lcs[m-1][n] > lcs[m][n-1])
                afiseazaSir(a,b, m-1, n);
            else
                afiseazaSir(a,b, m, n-1);
        }
        else
        {
            afiseazaSir(a,b,m-1,n-1);
            fout << a[m-1] << ' ';
        }
    }
}

int main()
{
    int m, n;
    fin >> m >> n;
    int a[m], b[n];
    for(int i=0; i<m; ++i)
        fin >> a[i];
    for(int i=0; i<n; ++i)
        fin >> b[i];
    for(int i=0; i<=m; ++i)
        for(int j=0; j<=n; ++j)
        {
            if(i==0  || j==0)
                lcs[i][j]=0;
            else if(a[i-1] == b[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    fout << lcs[m][n] << '\n';
    afiseazaSir(a,b, m, n);
    return 0;
}
