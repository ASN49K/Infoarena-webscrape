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
int a[NMAX], b[NMAX], c[2][NMAX], father[NMAX][NMAX];


void compute_cmlsc() {

    int count = 0;

    for (int i = 1; i <= na; i++) {
        for (int j = 1; j <= nb; j++) {
            if (a[i] == b[j]) {
                c[count][j] = c[1 - count][j - 1] + 1;
                father[i][j] = DIAG;
            } else {
                if (c[1 - count][j] < c[count][j - 1]) {
                    c[count][j] = c[count][j - 1];
                    father[i][j] = UP;
                } else {
                    c[count][j] = c[1 - count][j];
                    father[i][j] = LEFT;
                }
            }
        }
        count = 1 - count;
    }
    printf("%d\n", c[1 - count][nb]);
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
    print_cmlsc(na, nb);
    printf("\n");

    return 0;
}
