#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define MAX 1050
#define cout fout
int a[MAX][MAX];
int b[MAX], c[MAX];

void af(int n, int m)
{
    if(a[n][m])
    {
        if(b[n] == c[m])
        {
            af(n - 1, m - 1);
            cout << b[n] << " ";
        }
        else if(a[n - 1][m] > a[n][m - 1])
            af(n - 1, m);
        else
            af(n, m - 1);
    }
}

int main()
{
    int n, m, i, j;
    fin >> n >> m;
    for(i = 1 ; i <= n ; i++)
    {
        fin >> b[i];
    }
    for(i = 1 ; i <= m ; i++)
    {
        fin >> c[i];
    }
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= m ; j++)
        {
            if(b[i] == c[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
    }
    cout << a[n][m] << "\n";
    af(n, m);

}
