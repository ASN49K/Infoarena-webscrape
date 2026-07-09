#include <cstdio>
#include <iostream>
using namespace std;

int n, m, a[260], b[260], subsirNou[260], k;

int lcs[260][260];

void Citire()
{
    scanf("%i", &n);
    scanf("%i", &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%i", &b[i]);
    }
}

int CelMaiLungSubsirComun(int a[], int b[], int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs[n][m];
}

void Reconstituire()
{
    int i = n, j = m;
    k = 0;
    while (i && j)
    {
        if (a[i] == b[j])
        {
            k++;
            subsirNou[k] = a[i];
            i--;
            j--;
        }
        else if (lcs[i][j - 1] < lcs[i - 1][j])
        {
            i --;
        }
        else
        {
            j--;
        }
    }
    for (int i = k; i >= 1; i--)
    {
        printf("%i ", subsirNou[i]);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    Citire();

    k = CelMaiLungSubsirComun(a, b, n, m);
    printf("%i\n", k);
    Reconstituire();
    /*for (int i = 1; i <= n; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
    for (int i = 1; i <= m; i++)
    {
        printf("%i ", b[i]);
    }*/
    return 0;
}
