#include <cstdio>

using namespace std;

int N, T, x;

int main() {
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    scanf("%d\n", &T);

    while(T) {
        --T;

        scanf("%d\n", &N);

        int sum = 0;

        for(int i = 1; i <= N; ++i) {
            scanf("%d", &x);

            sum ^= x;
        }

        if(sum > 0) {
            printf("DA\n");
        }
        else {
            printf("NU\n");
        }
    }

    return 0;
}
