#include<fstream>
using namespace std;
ofstream out("cmlsc.out");
ifstream in("cmlsc.in");
const int MMAX = 1024;

int n, m, lg, Max;
int a[MMAX], b[MMAX], sol[MMAX+1][MMAX+1];

void citire()
{
    in >> n >> m;
    for(int i=1; i<=n; i++) in >> a[i];
    for(int i=1; i<=m; i++) in >> b[i];
}

void dinamica()
{
    for(int i=2; i<=m+1; i++)
        for(int j=2; j<=n+1; j++)
        {
            if(b[i-1] == a[j-1])
                sol[i][j] = sol[i-1][j-1] + 1;
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
        }
}

void baieteala(int i, int j)
{
    if(sol[i][j])
    {
        if(sol[i][j-1] == sol[i][j]) baieteala(i, j-1);
        else if(sol[i-1][j] == sol[i][j]) baieteala(i-1, j);
        else
        {
            baieteala(i-1, j-1);
            out << b[i-1] << ' ';
        }
    }
}

int main()
{
    citire();
    dinamica();

    for(int i=2; i<=n+1; i++)
        if(sol[m+1][i] > lg)
            lg = sol[m+1][i];
    out << lg << '\n';

    baieteala(m+1, n+1);

    in.close();
    out.close();
    return 0;
}
