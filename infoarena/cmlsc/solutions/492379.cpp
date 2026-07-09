#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

#define infile "cmlsc.in"
#define outfile "cmlsc.out"

#define NMAX 1026

FILE *fin, *fout;

#define UP 1
#define LEFT 2
#define DIAG 3

int na, nb;
int a[NMAX], b[NMAX], c[NMAX][NMAX], father[NMAX][NMAX];


void compute_cmlsc() {

    for (int i = 1; i <= na; i++) 
        for (int j = 1; j <= nb; j++) {
            if (a[i] == b[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                father[i][j] = DIAG;
            } else {
                if (c[i - 1][j] < c[i][j - 1]) {
                    c[i][j] = c[i][j - 1];
                    father[i][j] = UP;
                } else {
                    c[i][j] = c[i - 1][j];
                    father[i][j] = LEFT;
                }
            }
        }
}

void print_cmlsc(int i, int j) {
    if (i == 0 && j == 0)
        return;

    switch (father[i][j]) {
        case UP:
            print_cmlsc(i, j - 1);            
            break;
        case LEFT:
            print_cmlsc(i - 1, j);            
            break;
        case DIAG:
            print_cmlsc(i - 1, j - 1);            
            printf("%d ", a[i]);
            break;
    }
}

int main() {

    fin = freopen(infile, "r", stdin);
    fout = freopen(outfile, "w", stdout);

    scanf("%d%d", &na, &nb);

    for (int i = 1; i <= na; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= nb; i++)
        scanf("%d", &b[i]);

    compute_cmlsc();
    printf("%d\n", c[na][nb]);
    print_cmlsc(na, nb);
    printf("\n");

    return 0;
}
