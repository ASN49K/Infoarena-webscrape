#include <cstdio>
#define N   100005
using namespace std;
int n, i, j, v[N], Lmax[N], urm[N], max, sol, p;

void citire() {
    freopen ("scmax.in", "r", stdin);
    freopen ("scmax.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &v[i]);
}
void dinamic() {
    int i, j;
    Lmax[n] = 1;
    urm[n] = -1;
    max = 1;
    p = n;
    for (i=n-1; i>=1; --i) {
        Lmax[i] = 1;
        urm[i] = -1;
        for (j=i+1; j<=n; ++j) {
            if (v[i] < v[j] && Lmax[i] < Lmax[j]+1) {
                Lmax[i] = 1 + Lmax[j];
                urm[i] = j;
                if (Lmax[i] > max) {
                    max = Lmax[i];
                    p = i;
                }
            }
        }
    }
}

void constructie() {
    int i;
    i = p;
    while (i != -1) {
        printf ("%d ", v[i]);
        i = urm[i];
    }
}

int main()
{
    citire();
    dinamic();
    printf ("%d\n", max);
    constructie();
    return 0;
}
