#include <fstream>
#include <iostream>
#include <algorithm>

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

int a[1025], b[1025], v[1025], viz[1025], v1[1025], v2[1025];

void afis(int i) {
    if (i != -1)
    {
        afis(v2[i]);
        g << b[i] << " ";
    }
}
int main()
{
    int m, n;
    f >> m >> n;
    for (int i = 0; i < m; i++)
        f >> a[i];
    for (int i = 0; i < n; i++)
        f >> b[i];
    int size = std::max(m, n);
    for (int i = 0; i < size; i++)
        viz[i] = -1;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j] && viz[j] == -1)
                viz[j] = i;
        }
    for (int i = 0; i < size; i++)
    {
        v1[i] = 1;
        v2[i] = -1;
    }
    int maxim = -1, poz = -1;
    if (viz[0] != -1)
    {
        maxim = 1;
        poz = 0;
    }
    for (int i = 0; i < size; i++) {
        if (viz[i] != -1)
        {
            for (int j = i - 1; j >= 0; j--)
                if (viz[j] < viz[i] && v1[j] + 1 > v1[i] && viz[j] != -1)
                {
                    v1[i] = v1[j] + 1;
                    v2[i] = j;
                    if (v1[i] > maxim)
                    {
                        maxim = v1[i];
                        poz = i;
                        std::cout << poz;
                    }
                }
            if (v1[i] > maxim)
            {
                maxim = v1[i];
                poz = i;
                std::cout << poz;
            }

        }
    }
    g << maxim << '\n';
    afis(poz);
    return 0;
}