#include <cstdio>

using namespace std;

int cmmdc (int x, int y){
    if (y == 0){
        return x;
    }
    return cmmdc (y, x % y);
}

void  citire(){
    int t;
    scanf ("%d", &t);
    while (t--){
        int x;
        int y;
        scanf ("%d%d", &x, &y);
        printf ("%d\n", cmmdc (x, y));
    }
}

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);

    citire();

    return 0;
}
