#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m;
int bst;
int a[1030], b[1030];
int sir[1030];
int M[1030][1030];

void citire();
void pd ();

int main()
{
    citire();
    pd();
    return 0;
}

void citire()
{
    int i;
    fin>>m>>n;
    for(i=1; i<=m; ++i)
        fin>>a[i];
    for(i=1; i<=n; ++i)
        fin>>b[i];
}

void pd ()
{
    int i, j, k, gasit;
    for(i=1; i<=n; ++i)
        M[0][i]=0;
    for(i=1; i<=m; ++i)
        M[i][0]=0;

    for(i=1; i<=m; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            gasit=0;
            for(k=j; k>=1; --k)
            {
                if(a[i]==b[k])
                    gasit=1;
                if( M[i][j] < (M[i-1][k]+gasit) )
                    M[i][j] = (M[i-1][k]+gasit);
            }
        }
    }
    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (M[i-1][j] < M[i][j-1])
            --j;
        else
            --i;
    fout<<M[m][n]<<'\n';

    for(i=bst; i>=1; --i)
        fout<<sir[i]<<' ';
}
