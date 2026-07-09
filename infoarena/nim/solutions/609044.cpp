# include <cstdio>

const char *FIN = "nim.in", *FOU = "nim.out";

int T;

int main (void) {
    freopen (FIN, "r", stdin);
    freopen (FOU, "w", stdout);

    for (scanf ("%d", &T); T; --T) {
        int sum = 0, N;
        scanf ("%d", &N);
        for (int i = 1, x; i <= N; ++i) {
            scanf ("%d", &x);
            sum ^= x;
        }
        printf ("%s\n", sum ? "DA" : "NU");
    }
}
