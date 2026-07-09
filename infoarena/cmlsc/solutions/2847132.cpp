#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int cmlsc[1025][1025], sm[1025], sn[1025], rez[1025];

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
    int i=m, j=n, k=cmlsc[m][n];
    while (i&&j)
    {
        if (sm[i]==sn[j])
        {
            rez[k--]=sm[i];
            i--; j--;
        }
        else if (cmlsc[i][j-1] > cmlsc[i-1][j])
            j--;
        else
            i--;
    }
    for (k=1; k<=cmlsc[m][n]; k++)
        fout<<rez[k]<<" ";
	return 0;
}
