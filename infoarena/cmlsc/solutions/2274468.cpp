#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int vec1[1025];
int vec2[1025];
int best[1025][1025];
int total, poz_i_tot, poz_j_tot;
int sol[1025];
void build(int x, int y);
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
    int k=total;
    fout<<total<<'\n';
    build(poz_i_tot, poz_j_tot);
    for(int i=1; i<=k; i++) fout<<sol[i]<<' ';
    return 0;
}
void build(int x, int y)
{
    if(!total)  return;
    if(vec1[x]==vec2[y])
    {
        sol[total--]=vec1[x];
        build(x-1, y-1);
    }
    else if(best[x-1][y]>best[x][y-1])  build(x-1, y);
    else build(x, y-1);
}
