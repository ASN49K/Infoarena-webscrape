#include <fstream>

using namespace std;

int n,m,a[1030],b[1030],sol[1030][1030],sol2[1030];

int main ()
{
    ifstream in ("cmlsc.in");
    ofstream out ("cmlsc.out");

    in>>n>>m;
    for (int i=1;i<=n;++i) in>>a[i];
    for (int i=1;i<=m;++i) in>>b[i];

    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (a[i]==b[j])
                sol[i][j]=sol[i-1][j-1]+1;
            if (sol[i-1][j]>sol[i][j]) sol[i][j]=sol[i-1][j];
            if (sol[i][j-1]>sol[i][j]) sol[i][j]=sol[i][j-1];
        }
    }

    out<<sol[n][m]<<"\n";
    int i=n,j=m,nr=0;
    while(nr<sol[n][m])
    {
        while (sol[i-1][j]==sol[i][j]) --i;
        while (sol[i][j-1]==sol[i][j]) --j;
        ++nr;
        sol2[nr]=a[i];
        --i;--j;
    }
    for (int i=nr;i>0;--i) out<<sol2[i]<<" ";

    in.close();
    out.close();
    return 0;
}
