#include <fstream>
using namespace std;

int i, j, n, m;
short a[1027], b[1027], sir[1027], sol[1027], lmax;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int Subsir(int lg)
{
    int i, j;
    j=1;
    for (i=1; i<=m && j<=lg; ++i)
        if (b[i]==sir[j])
            ++j;
    if (j>lg)
        return 1;
    return 0;
}

void BT(int poz, int lg)
{
    if (poz>n) {
        if (Subsir(lg)) {
            if (lg>lmax) {
                lmax=lg;
                for (int j=1; j<=lg; ++j)
                    sol[j]=sir[j];
            }
        }
        return ;
    }
    BT(poz+1, lg);
    sir[lg+1]=a[poz];
    BT(poz+1, lg+1);
}

int main()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>a[i];
    for (i=1; i<=m; ++i)
        f>>b[i];
    BT(1, 0);
    g<<lmax<<'\n';
    for (i=1; i<=lmax; ++i)
        g<<sol[i]<<' ';
    return 0;
}
