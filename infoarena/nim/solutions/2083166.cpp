#include <cstdio>

using namespace std;

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t --) {
        int n, sum = 0;
        scanf("%d", &n);

        for(int i = 1; i <= n; ++ i) {
            int x;
            scanf("%d", &x);

            sum ^= x;
        }

        if(sum) {
            printf("DA\n");
        } else {
            printf("NU\n");
        }
    }

    return 0;
}
