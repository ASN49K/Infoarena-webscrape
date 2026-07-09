#include <cstdio>
#include <algorithm>

using namespace std;

const int NMAX = 1100;
int lenA, lenB, A[NMAX], B[NMAX], ANS[NMAX], d[NMAX][NMAX];

void dynLCS () {
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i] == B[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else {
                d[i][j] = max (d[i - 1][j], d[i][j - 1]);
            }
        }
    }
}

void reconLCS (int i, int j, int lenANS) {
    if (i == 0 || j == 0) {
        return;
    }
    if (A[i] == B[j]) {
        ANS[lenANS] = A[i];
        reconLCS (i - 1, j - 1, lenANS - 1);
    }
    else {
        if (d[i][j] == d[i - 1][j]) {
            reconLCS (i - 1, j, lenANS);
        }
        else {
            reconLCS (i, j - 1, lenANS);
        }
    }
}

int main () {
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    scanf ("%d%d", &lenA, &lenB);
    for (int i = 1; i <= lenA; i++) {
        scanf ("%d", &A[i]);
    }
    for (int j = 1; j <= lenB; j++) {
        scanf ("%d", &B[j]);
    }

    dynLCS ();
    reconLCS (lenA, lenB, d[lenA][lenB]);

    printf ("%d\n", d[lenA][lenB]);
    for (int i = 1; i <= d[lenA][lenB]; i++) {
        printf ("%d ", ANS[i]);
    }
    return 0;
}
