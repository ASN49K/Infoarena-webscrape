#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

struct pd{int val, pre;};

int i, n, m, j;
pd U[1050][1050];
int H[1050], V[1050], Sol[1050], nr;

int main()
{
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>H[i];
    for (i=1; i<=m; i++)
        fin>>V[i];
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (V[i]==H[j])
            {
                U[i][j].val=U[i-1][j-1].val+1;
                U[i][j].pre=1;
            }
            else
            {
                if (U[i-1][j].val>U[i][j-1].val)
                {
                    U[i][j].val=U[i-1][j].val;
                    U[i][j].pre=2;
                }
                else
                {
                    U[i][j].val=U[i][j-1].val;
                    U[i][j].pre=3;
                }

            }
        }
    }
    i=m;
    j=n;
    fout<<U[i][j].val<<'\n';
    while (U[i][j].val!=0)
    {
        if (U[i][j].pre==1)
        {
            Sol[++nr]=V[i];
            i--;
            j--;
        }
        else
        {
            if (U[i][j].pre==2)
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for (i=nr; i>=1; i--)
        fout<<Sol[i]<<" ";
    return 0;
}
