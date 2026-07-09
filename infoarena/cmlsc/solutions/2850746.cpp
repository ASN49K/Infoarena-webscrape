#include <fstream>

#define NMAX 257

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int a, b, n, m, f[NMAX] = {0}, f1[NMAX] = {0}, maxim, vecfin[NMAX], k;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        f[a]++;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b;
        f1[b]++;
    }
    maxim = 0;
    k = 0;
    for(int i = 1; i <= 256; i++)
    {
        maxim += min(f[i], f1[i]);
        if(f[i] != 0 && f1[i] != 0)
            vecfin[++k] = i;
    }
    cout << maxim << "\n";
    for(int i = 1; i <= k; i++)
        cout << vecfin[i] << " ";
    return 0;
}
