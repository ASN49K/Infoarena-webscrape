#include <iostream>
#include <fstream>

#define MAX 1024

using namespace std;

void add_element(int v[MAX], int x, int &n)
{
    v[n] = x;
    n = n + 1;
}

int main()
{
    int a[MAX],b[MAX],c[MAX],
        n,m,i,j,k = 0,
        first = 1025,
        last_pos = -1;

    ifstream f;
    ofstream g;

    f.open("cmlsc.in");
    g.open("cmlsc.out");

    f >> m >> n;

    for (i = 0; i < m; i++) f >> a[i];
    for (i = 0; i < n; i++) f >> b[i];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (b[i] == a[j] && j > first && j > last_pos)
            {
                add_element(c,b[i],k);
                if (i == n - 1) break;
                last_pos = j;
                break;
            }
            else if (b[i] == a[j] && j < first)
            {
                k = 0;
                add_element(c,b[i],k);
                if (i == n - 1) break;
                first = j;
                last_pos = j;
                break;
            }
        }
    }

    g << k << '\n';
    for (i = 0; i < k; i++)
        g << c[i] << ' ';

    f.close();
    g.close();

    return 0;
}
