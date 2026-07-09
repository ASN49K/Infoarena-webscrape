#include <fstream>

using namespace std;

ifstream f("scmax.in");
ofstream g("scmax.out");

int a[100001], b[100001], c[100001];
int k, m, n, i, j, st, dr, poz;

int main()
{
    f >> n;
    for (i = 1; i <= n; i++)
        f >> a[i];

    b[0] = 0, k = 0;
    for (i = 1; i <= n; i++)
    {
        if (b[k] < a[i])
            k++, b[k] = a[i], c[i] = k;
        else
        {
            st = 1, dr = k, poz = k;
            while (st <= dr)
            {
                m = (st+dr)/2;
                if (b[m] < a[i])
                    st = m+1;
                else
                    dr = m-1, poz = m;
            }
            b[poz] = a[i];
            c[i] = poz;
        }
    }

    for (i = n, j = 0; i >= 1 && k > 0; i--)
        if (c[i] == k)
            j++, b[j] = a[i], k--;

    g << j << "\n";
    for (i = j; i >= 1; i--)
        g << b[i] << " ";
    return 0;
}
