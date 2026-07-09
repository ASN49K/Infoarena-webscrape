#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax = 1005;
int d[nmax][nmax], s1[nmax], s2[nmax], sol[nmax];
int nrs;
int main()
{
    int n,m;
    fin >> m >> n;
    for(int i=1; i<=m; ++i)
        fin>>s1[i];
    for(int i=1; i<=n; ++i)
        fin>>s2[i];
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            if(s1[i]==s2[j])
                d[i][j] = d[i-1][j-1]+1;
            else
                d[i][j] = max(d[i][j-1],d[i-1][j]);
    int i=m, j=n;
    while (i)
        if (s1[i]==s2[j])
            sol[++nrs] = s1[i], --i, --j;
        else if (d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    fout << nrs << "\n";
    while(nrs>=1) {
        fout << sol[nrs] << ' ';
        nrs--;
    }
    return 0;
}
