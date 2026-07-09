#include <iostream>
#include <fstream>
#include <vector>

#define MAX 1024

using namespace std;

void add_element(int v[MAX], int x, int &n)
{
    v[n] = x;
    n = n + 1;
}

void copy_vector(int v1[MAX], int v2[MAX], int n, int &m)
{
    m = n;
    for (int i = 0; i < n; i++)
        v2[i] = v1[i];
}

int main()
{
    int a[MAX], b[MAX], c[MAX], d[MAX], aux[MAX],
        n, m, i, j, k, l = 0, ok = 0,
        c_size = 0, d_size = 0,
        last_found;

    ifstream f;
    ofstream g;

    f.open("cmlsc.in");
    g.open("cmlsc.out");

    f >> m >> n;

    for (i = 0; i < m; i++) f >> a[i];
    for (i = 0; i < n; i++) f >> b[i];

    for (i = 0; i < n; i++)
    {
        k = i; l = 0;
        while (k < n)
        {
            for (j = l; j < m && k < n; j++)
            {
                if (a[j] == b[k])
                {
                    add_element(c,b[k],c_size);
                    k++;
                    l = j;
                }
            }
            if (l) l++;
            k++;
        }

        if (c_size > d_size)
        {
            copy_vector(c,d,c_size,d_size);
        }
        c_size = 0;
    }

    g << d_size << '\n';
    for (i = 0; i < d_size; i++)
    {
        g << d[i] << ' ';
    }

    f.close();
    g.close();

    return 0;
}
