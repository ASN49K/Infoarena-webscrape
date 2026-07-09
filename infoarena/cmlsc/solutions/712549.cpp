#include <cstdio>
#define nMax 1030
#define max(a,b) ((a>b)?a:b)

using namespace std;

int n;
int m;
int a[nMax];
int b[nMax];
int sol[nMax][nMax];

void citire()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++ i){
        scanf ("%d", &b[i]);
    }
}

void rez()
{
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (a[i] == b[j]){
                sol[i][j] = 1 + sol[i - 1][j - 1];
            }else{
                sol[i][j] = max (sol[i - 1][j], sol[i][j - 1]);
            }
        }
    }
    printf ("%d\n", sol[n][m]);
}

void afis(int i, int j)
{
    if (i == 0){
        return;
    }
    if (a[i] == b[j]){
        afis (i - 1, j - 1);
        printf ("%d ", a[i]);
        return;
    }
    if (sol[i][j - 1] > sol [i - 1][j]){
        afis (i, j - 1);
        return;
    }
    afis (i - 1, j);
}

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    citire();
    rez();
    afis(n,m);

    return 0;
}
