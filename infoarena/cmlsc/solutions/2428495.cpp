#include <fstream>
#include <algorithm>
#define FOR(I,J,N,M) for(I=1,J=1;i<=N;I++)for(;J<=M;J++)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int D[1025][1025],n,m,i,j,sol[1024],v1[1024],v2[1024],idx;
void read(int v[], int length)
{
    for (i=0;i<length;i++)
        f>>v[i];
}
int main()
{
    f >> n >> m;
    read(v1,n),read(v2,m);
    FOR(i,j,n,m)
        if (v1[i-1]==v2[j-1])
            D[i][j]+=(D[i-1][j-1]+1);
        else
            D[i][j] = max(D[i-1][j], D[i][j-1]);
    for (i=n, j=m; i;)
        if (v1[i-1] == v2[j-1])
            sol[idx++] = v1[i-1], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    g << idx << '\n';
    for (i=idx-1;i>=0;--i)g<<sol[i]<<' ';
    return 0;
}
