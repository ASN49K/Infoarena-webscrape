#include <iostream>
#include <cstring>
#include <cstdio>
#define LMAX 1024

using namespace std;
int m, n;
int a[LMAX];
int b[LMAX];
int vec[LMAX];
bool done = false;

void afiseaza(int nrComb)
{
    printf("%d\n", nrComb);
    for (int i=1; i<=nrComb; i++)
    {
        printf("%d ", a[vec[i]]);
    }
}
bool subsir(int nrComb)
{
    int aux[LMAX];
    int l = 1;
    for (int i=1; i<=nrComb; i++)
    {
        aux[i] = a[vec[i]];
    }

    for (int i=1; i<=max(m, n); i++)
    {
        if (aux[l] == b[i])
        {
            l++;
        }

        if (l-1 == nrComb)
            return true;
    }

    return false;
}

void bt(int nrComb, int k = 1)
{
    if (k == nrComb+1)
    {
        if (subsir(nrComb))
        {
            afiseaza(nrComb);
            done = true;
        }
        return;
    }

    for (int i=vec[k-1]+1; i<=min(m, n) && !done; i++)
    {
        vec[k] = i;
        bt(nrComb, k+1);
    }
}

void read()
{
    scanf("%d %d\n", &m, &n);
    if (m > n)
    {
        for (int i=1; i<=m; i++)
            scanf("%d ", &b[i]);
            scanf("\n");
        for (int i=1; i<=n; i++)
            scanf("%d ", &a[i]);
    }
    else
    {
        for (int i=1; i<=m; i++)
            scanf("%d ", &a[i]);
            scanf("\n");
        for (int i=1; i<=n; i++)
            scanf("%d ", &b[i]);
    }

}

void solve()
{
    for (int i=min(m, n); i>=1; i--)
    {
        bt(i);
        if (done)
            return;
        memset(vec, 0, sizeof(vec));
    }
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    read();
    solve();
    return 0;
}
