#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> primes;
vector <int> V(1000003, 0);

    FILE * F = fopen ("joc18.in", "r");
    FILE * G = fopen ("joc18.out", "w");

void getPrimes() {
    int i, j;
    for (i = 2; i < 1000003; ++i) {
        if (V[i] == 0) {
            V[i] = 1;
            for (j = i + i; j < 1000003; j += i) {
                int aux = j;
                while (aux % i == 0) {
                    ++V[j];
                    aux /= i;
                }
            }
        }
    }
}

void solve() {
    int N, i, x;
    int nr1 = 0, sum1 = 0;
    int minn = 1 << 29;
    int maxx = 0;
    fscanf(F, "%d", &N);
    for (i = 0; i < N; ++i) {
        fscanf(F, "%d", &x);
        if (x == 1) {
            ++nr1;
        }
        else {
            int ans = V[x];

                minn = min ( minn, ans);
                maxx = max ( maxx, ans);
        }
    }
    if (nr1 == N) {
        fprintf(G, "Aurel\n");
        return;
    }
    if (nr1 > 0) {
        fprintf(G, "Bianca\n");
        return;
    }
    if (nr1 == 0) {
        if (minn == maxx) {
            fprintf(G, "Aurel\n");
            return;
        }
        else {
            fprintf(G, "Bianca\n");
            return;
        }
    }
}

int main()
{
    int T;
    getPrimes();
    fscanf(F, "%d", &T);
    while (T--) {
        solve();
    }

    return 0;
}
