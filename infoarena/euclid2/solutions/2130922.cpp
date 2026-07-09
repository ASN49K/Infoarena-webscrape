#include <cstdio>

using namespace std;

int n;

int euclid(int x, int y){
    while(y != 0){
        int z = x % y;
        x = y;
        y = z;
    }

    return x;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

    int x, y;

    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        printf("%d\n", euclid(x, y));
    }


    return 0;
}
