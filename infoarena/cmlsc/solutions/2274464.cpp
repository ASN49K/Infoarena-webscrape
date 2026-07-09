#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int vec1[1025];
int vec2[1025];
int best[1025][1025];
int total, poz_i_tot, poz_j_tot;
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++) fin>>vec1[i];
    for(int i=1; i<=m; i++) fin>>vec2[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(vec1[i]==vec2[j])    best[i][j]=1+best[i-1][j-1];
            else    best[i][j]=max(best[i-1][j], best[i][j-1]);
            if(best[i][j]>total)
            {
                total=best[i][j];
                poz_i_tot=i;
                poz_j_tot=j;
            }
        }
    fout<<total<<'\n';
    return 0;
}
