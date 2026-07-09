#include <cstdio>
using namespace std;

int main(){

    int T, N, x, xorSum;

    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &T);

    while(T--){
        scanf("%d", &N);
        xorSum = 0;

        while(N--){
            scanf("%d", &x);
            xorSum ^= x;
        }
        if(xorSum) printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
