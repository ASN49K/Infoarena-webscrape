#include <fstream>

using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

int n, i, j, a[100001];
int b[100001], k;
int c[100001];

int main()
{
    f >> n;
    for (i = 1; i <= n; i++)
        f >> a[i];

    for (i = 1; i <= n; i++)
        if (a[i] > b[k])
            b[++k] = a[i], c[i] = k;
        else
        {
            int st = 1, dr = k, poz = k;
            int m;
            while (st <= dr)
            {
                m = (st+dr)/2;
                if (b[m] >= a[i])
                    dr = m-1, poz = m;
                else
                    st = m+1;
            }
            b[poz] = a[i];
            c[i] = poz;
        }
    j = k;
    k = 0;
    for (i = n; i >= 1 && j > 0; i--)
        if (c[i] == j)
            b[++k] = a[i], j--;
    g << k << "\n";
    for (i = k; i >= 1; i--)
        g << b[i] << " ";
    return 0;
}
