#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int cmlsc[1025][1025], sm[1025], sn[1025];

int main()
{
    int m, n;
    fin>>m>>n;
    for (int i=1; i<=m; i++)
        fin>>sm[i];
    for (int i=1; i<=n; i++)
        fin>>sn[i];

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (sm[i]==sn[j])
                cmlsc[i][j] = cmlsc[i-1][j-1]+1;
            else
                cmlsc[i][j] = max(cmlsc[i][j-1], cmlsc[i-1][j]);

    fout<<cmlsc[m][n]<<'\n';
    for (int i=1; i<=m; i++)
    {
        if (cmlsc[i][n]>cmlsc[i-1][n])
            fout<<sm[i]<<" ";
    }
	return 0;
}
