#include <fstream>
using namespace std;
int sol[1030], a[1030], b[1030], d[1030][1030],  dim, n, m, i, j, val;
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>a[i];
    for (i=1; i<=m; i++)
        fin>>b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
    val=d[n][m];
    fout<<val<<"\n";
    i=n;
    j=m;
    while (val>0)
    {
        if (a[i]==b[j]) {
            sol[++dim]=a[i];
            val--;
            i--;
            j--;
        }
        else
        {
            if (d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
        }
    }
    for (int i=dim; i>=1; i--)
        fout<<sol[i]<<" ";
}
