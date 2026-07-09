#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[1025], w[1025], mat[1025][1025], aux[1025];
int main()
{
    int n, m, i, j, nr=0;
    fin >> n >> m;
    for(i=1; i<=n; i++)
        fin >> v[i];
    for(j=1; j<=m; j++)
        fin >> w[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(v[i]==w[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
        }
    i=n; j=m;
    while(i && j)
    {
        if(v[i]==w[j])
        {
            nr++;
            aux[nr]=v[i];
            i--;
            j--;
        }
        else
            if(max(mat[i-1][j], mat[i][j-1])==mat[i-1][j])   i--;
        else   j--;
    }
    fout << mat[n][m] << "\n";
    while(nr)
    {
        fout << aux[nr] << " ";
        nr--;
    }
    return 0;
}
