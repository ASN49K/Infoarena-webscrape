#include <cstdio>

int **c, **b, n, m, max, r;
char *x, *y, *rez;
int main() {
    int i,j;
    FILE *fin = fopen("cmlsc.in", "r");
    FILE *fout = fopen("cmlsc.out", "w");
    
    fscanf(fin, "%d %d", &n, &m);
    
    x = new char[n+1];
    y = new char[m+1];
    
    if(m>n) {
        max = m;
    } else {
        max = n;
    }
    rez = new char[max];
    c = new int*[n+1];
    b = new int*[n+1];
    
    for(i = 0;i<n;i++) {
        fscanf(fin,"%d",&x[i+1]);
        c[i] = new int[m+1];
        b[i] = new int[m+1];
        c[i][0] = 0;
    }
    c[n] = new int[m+1];
    b[i] = new int[m+1];
    c[n][0] = 0;
    
    for(i=0;i<m;i++) {
        fscanf(fin,"%d",&y[i+1]);
        c[0][i] = 0;
    }
    c[0][m] = 0;
    
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            } else { // c[i][j] = max(c[i-1][j], c[i][j-1])
                if(c[i-1][j] > c[i][j-1]) {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 2;
                } else {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 0;
                }
            }
        }
    }
    
    fprintf(fout, "%d\n", c[n][m]);
    
    i = n;
    j = m;
    r = 0;
    
    while(i || j) {
        if(b[i][j] == 0) {
            j--;
        } else {
            if(b[i][j] == 1) {
                rez[r++] = x[i];
                i--;
                j--;
            } else {
                i--;
            }
        }
    }

    
   for(i=r-1;i>=0;i--) {
        fprintf(fout, "%d ", rez[i]);
    }
    return 0;
}
