#include <cstdio>

using namespace std;

int n;

int cmmdc (int x, int y)
{
    if (x < y){
        int aux = x;
        x = y;
        y = aux;
    }
    int r;
    while (y != 0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void citire()
{
    scanf ("%d", &n);
    while (n --){
        int x;
        int y;
        scanf ("%d%d", &x, &y);
        printf ("%d\n", cmmdc(x,y));
    }
}

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    citire();

    return 0;
}
