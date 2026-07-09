#include <cstdio>

int **c, n, m;
char *x, *y;

void print(int i, int j, FILE *fout) {
    if(!i || !j) {
        return ;
    }
    if(c[i][j]%10 == 0) {
            print(i,j-1,fout);
        } else {
            if(c[i][j]%10 == 1) {
                print(i-1,j-1,fout);
                fprintf(fout, "%d ", x[i]);
            } else {
                print(i-1,j,fout);
            }
        }
    }
    


int main() {
    int i,j;
    FILE *fin = fopen("cmlsc.in", "r");
    FILE *fout = fopen("cmlsc.out", "w");
    
    fscanf(fin, "%d %d", &n, &m);
    
    x = new char[n+1];
    y = new char[m+1];
    
    c = new int*[n+1];

    
    for(i = 0;i<n;i++) {
        fscanf(fin,"%d",&x[i+1]);
        c[i] = new int[m+1];
        c[i][0] = 0;
    }
    c[n] = new int[m+1];

    c[n][0] = 0;
    
    for(i=0;i<m;i++) {
        fscanf(fin,"%d",&y[i+1]);
        c[0][i] = 0;
    }
    c[0][m] = 0;
    
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(x[i] == y[j]) {
                c[i][j] = (c[i-1][j-1]/10 + 1) * 10 + 1;
            } else { // c[i][j] = max(c[i-1][j], c[i][j-1])
                if(c[i-1][j]/10 > c[i][j-1]/10) {
                    c[i][j] = c[i-1][j]/10 * 10 + 2;
                } else {
                    c[i][j] = c[i][j-1]/10 * 10;
                }
            }
        }
    }
    
    fprintf(fout, "%d\n", c[n][m]/10);
    
    print(n,m,fout);

    return 0;
}
