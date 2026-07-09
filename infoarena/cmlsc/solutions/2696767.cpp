#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMmax = 1024;

int mat[NMmax + 2][NMmax + 2];
int s1[NMmax + 2], s2[NMmax + 2];

void memorizare(int i, int j)
{
    while(s1[i] != s2[j])
    {
        if(mat[i-1][j] > mat[i][j-1])
        {
            i--;
        }
        else
            j--;
    }
    if(mat[i-1][j-1] > 0)
        memorizare(i-1, j-1);
    out << s1[i] << " ";
}

void rezolvare(int n, int m, int &imax, int &jmax)
{
    register int i, j;
    bool ok = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(s1[i] == s2[j])
            {
                mat[i][j] = mat[i-1][j-1] + 1;
                if(ok == 0)
                {
                    ok = 1;
                    imax = i;
                    jmax = j;
                }
                else
                {
                    if(mat[i][j] > mat[imax][jmax])
                    {
                        imax = i;
                        jmax = j;
                    }
                }

            }
            else
            {
                mat[i][j] = max(mat[i-1][j], mat[j][i-1]);
            }
        }
    }
}

void afis(int n, int m)
{
    register int i, j;
    for(i = 1 ; i <= n; i++)
    {
        for(j = 1 ; j <= m; j++)
            out<<mat[i][j];
        out << '\n';
    }

}

void citire(int &n, int &m)
{
    in >> n >> m;
    register int i;
    for(i = 1 ; i <= n; i++)
        in>>*(s1+i);
    for(i = 1 ; i <= m; i++)
        in>>*(s2+i);
}

int main()
{
    int n, m;
    int imax, jmax;
    citire(n, m);
    rezolvare(n, m, imax, jmax);
    //afis(n, m);
    out << mat[imax][jmax]<<'\n';
    memorizare(imax, jmax);
    return 0;
}
