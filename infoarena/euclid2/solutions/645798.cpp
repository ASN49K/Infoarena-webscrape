#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        if (b > a) {
            int c = a;
            a = b;
            b = c;
        }

        while (b > 1) {
            int c = a;
            a = b;
            b = c % b;
        }
        printf("%d\n", b==1?1:a);
    }

    return 0;
}

