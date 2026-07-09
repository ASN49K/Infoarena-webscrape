#include <fstream>
#define in "cmlsc.in"
#define out "cmlsc.out"
#define max(a,b) (a>b ? a:b)
#define N 1030

using namespace std;

ifstream fin(in);
ofstream fout(out);

short a[N],b[N],v[N][N];
int s[N];
int n,m;

void afisare()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
            fout<<v[i][j]<<" ";
        fout<<"\n";
    }
}
inline void solve(int i2,int j2)
{
    if(v[i2][j2] == 0) return;
    if(v[i2-1][j2] == v[i2][j2]) solve(i2-1,j2);
    else if(v[i2][j2-1] == v[i2][j2]) solve(i2,j2-1);
    else
    {
        solve(i2-1,j2-1);
        fout<<a[i2]<<" ";
    }
}

int main()
{
    fin>>n>>m;

    for(int i=1; i<=n; ++i)
        fin>>a[i];
    for(int i=1; i<=m; ++i)
        fin>>b[i];

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            v[i][j] = max(max(v[i-1][j] , v[i][j-1]) , (a[i] == b[j] ? v[i-1][j-1]+1 : 0));

    //afisare();

    fout<<v[n][m]<<"\n";
    solve(n,m);

    fin.close(); fout.close();
    return 0;
}
