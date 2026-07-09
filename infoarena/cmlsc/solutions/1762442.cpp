#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int maxim(int a, int b)
{
    return (a > b) ? a : b;
}

void solutie(int *v, int *w, int n, int m)
{
    int i, j;
    int **a = new int*[n + 1];
    for(i = 0; i < n + 1; i++)
        a[i] = new int[m + 1];

    for(i = 0; i < n + 1; i++)
        a[i][0] = 0;
    for(j = 0; j < m + 1; j++)
        a[0][j] = 0;

    for(i = 1; i < n + 1; i++)
        for(j = 1; j < m + 1; j++)
            if(v[i] == w[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = maxim(a[i - 1][j], a[i][j - 1]);
    i = n;
    j = m;

    int *sol = new int[a[n][m]];
    int k = 0;
    while(a[i][j] != 0)
    {
        while(a[i][j - 1] == a[i][j])
            j--;
        while(a[i - 1][j] == a[i][j])
            i--;
        sol[k] = v[i];
        k++;
        i--;
        j--;
    }
    g << a[n][m] << "\n";
    for(i = k - 1; i > -1; i--)
        g << sol[i] << " ";

    delete[] sol;
    for(i = 0; i < n + 1; i++)
        delete[] a[i];
    delete[] a;
}

int main()
{
    int n, m, i;

    f >> n >> m;
    int *v = new int[n + 1];
    v[0] = 0;
    for(i = 1; i < n + 1; i++)
        f >> v[i];

    int *w = new int[m + 1];
    w[0] = 0;
    for(i = 1; i < m + 1; i++)
        f >> w[i];

    solutie(v, w, n, m);

    delete[] v;
    delete[] w;
    return 0;
}
