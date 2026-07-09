#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int x[1024], y[1024], a[100][100], m, n, v[1024], k;
void citire()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> x[i];
    for (i = 1; i <= m; i++)
        fin >> y[i];
    fin.close();
}
int maxim(int x, int y)
{
    if (x > y)
        return x;
    return y;
}
void dinamic()
{
    int i, j;
    for (i = 0; i <= n; i++)
        a[i][0] = 0;
    for (j = 0; j <= m; j++)
        a[0][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (x[i] == y[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else 
                a[i][j] = maxim(a[i - 1][j], a[i][j - 1]);
    fout << a[n][m] << "\n";
}
void afisare(int i, int j) 
{
    
    k = 0;
    while (i > 0 && j > 0)
    {
        if (x[i] == y[j]) 
        { 
            v[++k] = x[i];
            i--; 
            j--; 
        }
        else if (a[i][j] == a[i - 1][j])
            i--;
        else if (a[i][j] == a[i][j - 1])
            j--;
    }
    for (i = k; i >= 1; i--)
        fout << v[i] << " ";
}


int main()
{
    citire();
    dinamic();
    afisare(n, m);
    return 0;
}

