#include<fstream>
using namespace std;
ofstream fout("cmlsc.out");
ifstream fin("cmlsc.in");
const int MMAX = 256;

int n, m, lg, Max;
int a[MMAX], b[MMAX], sol[MMAX+1][MMAX+1];

void citire()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++) fin >> a[i];
    for(int i=1; i<=m; i++) fin >> b[i];
}

void pd()
{
    for(int i=2; i<=m+1; i++)
        for(int j=2; j<=n+1; j++) {
            if(b[i-1] == a[j-1])
                sol[i][j] = sol[i-1][j-1] + 1;
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
    }
}

void traceback(int i, int j)
{
    if(sol[i][j]) {
        if(sol[i][j-1] == sol[i][j]) traceback(i, j-1);
        else if(sol[i-1][j] == sol[i][j]) traceback(i-1, j);
        else {
            traceback(i-1, j-1);
            fout << b[i-1] << ' ';
        }
    }
}

int main()
{
    citire();
    pd();

    for(int i=2; i<=n+1; i++)
        if(sol[m+1][i] > lg)
            lg = sol[m+1][i];
    fout << lg << '\n';

    traceback(m+1, n+1);

    fin.close();
    fout.close();
    return 0;
}
