#include <fstream>
#define DMAX 101

using namespace std;

int n, m;
int a[DMAX],b[DMAX];
int LCS[DMAX][DMAX];
int OP[DMAX][DMAX];

void Citire();
void pd();
void afisare();

int main()
{
    Citire();
    pd();
    afisare();
    return 0;
}

void Citire()
{
    ifstream fin("cmlsc.in");

    fin >> n >> m;

    int i,j;
    for(i = 0; i < n; i++)
        fin >> a[i];
    for(j = 0; j < m; j++)
        fin >> b[j];

    fin.close();
}

void pd()
{
    int i, j;
    for(i = 0; i < n; i++)
        LCS[i][m] = 0;
    for(j = 0; j < m; j++)
        LCS[n][j] = 0;

    for(i = n-1; i >= 0; i--)
    {
        for(j = m-1; j >= 0; j--)
        {
            if(a[i] == b[j])
            {
                LCS[i][j] = 1 + LCS[i+1][j+1];
                OP[i][j] = 1;
            }
            else
            {
                if(LCS[i+1][j] > LCS[i][j+1])
                {
                    LCS[i][j] = LCS[i+1][j];
                    OP[i][j] = 2;
                }
                else
                {
                    LCS[i][j] = LCS[i][j+1];
                    OP[i][j] = 3;
                }
            }
        }
    }
}

void afisare()
{
    ofstream fout("cmlsc.out");
    fout << LCS[0][0] << '\n';

    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(OP[i][j] == 1)
            {
                fout << a[i] << ' ';
            }
            if(OP[i][j] == 2)
            {
                i++;
            }
            if(OP[i][j] == 3)
            {
                j++;
            }
        }
    }

    fout.close();
}
