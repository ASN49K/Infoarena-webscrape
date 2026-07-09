#include <stdio.h>
#define NMAX 1025

int n,m;
int X[NMAX],Y[NMAX];
int LMAX[NMAX][NMAX];
int T[NMAX][NMAX];
int lx,ly;

using namespace std;

int maxim(int a, int b) {
    if (a > b) return a;
    return b;
}
void printRec(int xi, int yi) {
    if (LMAX[xi][yi] == 0) return;
        if (X[xi] == Y[yi]) {
            printRec(xi-1,yi-1);
            printf("%d ",X[xi]);
        }
        else
         if (LMAX[xi][yi] == LMAX[xi-1][yi]) printRec(xi-1,yi);
          else
           printRec(xi,yi-1);

}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&lx,&ly);

    for(int i = 1; i <= lx; i++)
        scanf("%d",&X[i]);

    for(int i = 1; i <= ly; i++)
        scanf("%d",&Y[i]);

    for(int i = 1; i <= lx; i++)
        for(int j = 1; j <= ly; j++) {
            LMAX[i][j] = maxim(LMAX[i-1][j],LMAX[i][j-1]);
            if (X[i] == Y[j])
             LMAX[i][j] = maxim(LMAX[i][j], LMAX[i-1][j-1] + 1);
        }
    printf("%d\n",LMAX[lx][ly]);
    printRec(lx,ly);
    return 0;
}
