#include <cstdio>

using namespace std;

int main()
{
    freopen ("nim.in", "r", stdin);
    freopen ("nim.out", "w", stdout);

    int m;
    scanf ("%d", &m);
    while (m --){
        int x;
        int s = 0;
        scanf ("%d", &x);
        while (x --){
            int y;
            scanf ("%d", &y);
            s ^= x;
        }
        if (s){
            printf ("DA\n");
        }else{
            printf ("NU\n");
        }

    }

    return 0;
}
