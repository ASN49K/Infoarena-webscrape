///Nrx imi va datora un suc
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    FILE *fi = fopen("nim.in", "r");
    FILE *fo = fopen("nim.out", "w");
    int n, m, t, s;

    fscanf(fi,"%d",&n);
    while(n--) {
        s = 0;

        fscanf(fi,"%d",&m);
        for(int i=0; i<m; ++i) {
            fscanf(fi,"%d",&t);
            s^= t;
        }

        switch(s) {
        case 0:
            fprintf(fo,"NU\n");
            break;
        default:
            fprintf(fo,"DA\n");
        }
    }

    fclose(fi);
    fclose(fo);
    return 0;
}
