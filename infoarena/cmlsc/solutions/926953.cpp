#include <fstream>
#include <cstring>
#define MOD 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[MOD], b[MOD], sol[MOD], m[MOD][MOD], M, N, x, y, cnt, i, j;
int main()
{
    f>>M>>N;
    for(i=1; i<=M; i++)
		f>>a[i];
    for(i=1; i<=N; i++)
		f>>b[i];
    f.close();
    memset(m,0,sizeof(m));
    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            if(a[i]==b[j])
				m[i][j]=m[i-1][j-1]+1;
            else
				m[i][j]=max(m[i-1][j],m[i][j-1]);
    g<<m[M][N]<<"\n";
    memset(sol,0,sizeof(sol));
    x=M;
    y=N;
    cnt=m[x][y];
    while(cnt)
    {
        while(m[x][y]==m[x-1][y])
			x--;
        while(m[x][y]==m[x][y-1])
			y--;
        sol[cnt]=a[x];
        x--;
        y--;
        cnt--;
    }
    for(i=1; i<=m[M][N]; i++)
		g<<sol[i]<<' ';
    g<<"\n";
    g.close();
    return 0;
}
