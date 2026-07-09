#include<fstream>
using namespace std;


int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int a[1000], b[1000], sol[1000][1000], i, j, m, n;
    fin>>n>>m;
    for (i=1; i<=n; ++i) fin>>a[i];
    for (i=1; i<=m; ++i) fin>>b[i];

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j]) sol[i][j]=sol[i-1][j-1]+1;
                else sol[i][j]=max(sol[i-1][j], sol[i][j-1]);
}
