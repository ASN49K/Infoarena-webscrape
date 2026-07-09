#include <cstdio>
#include <vector>

using namespace std;
FILE *fin, *fout;

int n, m;
#define NMAX 1024
int v[NMAX + 5], x[NMAX + 5];  // v = A; x = B;
bool a[NMAX + 5][NMAX + 5];
vector <int> sol;

void citire()
{
    int i;
    for(i = 1; i <= m; i++)
        fscanf(fin, "%d", &v[i]);

    for(i = 1; i <= n; i++)
        fscanf(fin, "%d", &x[i]);
}

void build()
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(v[j] == x[i])
                a[i][j] = 1;
}

void print()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            fprintf(fout, "%d ", a[i][j]);

        fprintf(fout, "\n");
    }
}

void solve()
{
    int i, j, ind = 1 , cnt = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = ind; j <= m; j++)
            if(a[i][j] == 1)
            {
                cnt++;
                ind = j + 1;
                sol.push_back(v[j]);
                break;
            }
    }

    fprintf(fout , "%d\n" , cnt);

    for(auto nr : sol)
    {
        fprintf(fout, "%d ", nr);
    }
}

int main()
{
    fin = fopen("cmlsc.in", "r");
    fout = fopen("cmlsc.out", "w");

    fscanf(fin, "%d%d", &m, &n);

    citire();

    build();

    //print();

    solve();

    fclose(fin);
    fclose(fout);
    return 0;
}
