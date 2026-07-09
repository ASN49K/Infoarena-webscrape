#include <stdio.h>
#include <string.h>

using namespace std;

int a[1026], b[1026], l[1026][1026], f[1026];

int main()
{
    int m, n;
    FILE * fin = fopen("cmlsc.in", "r");
    FILE * fout = fopen("cmlsc.out", "w");
    fscanf(fin, "%d %d", &m, &n);

    for (int i=1; i<=m; i++)
        fscanf(fin, "%d", &a[i]);

    for (int i=1; i<=n; i++)
        fscanf(fin, "%d", &b[i]);

    a[0] = b[0] = 0;

    memset(l, 0, sizeof(l));


    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (a[i] == b[j])
                l[i][j] = l[i-1][j-1] + 1;

            else l[i][j] = (l[i-1][j] > l[i][j-1]) ? l[i-1][j] : l[i][j-1];
        }
    }

    int i=m, j=n, r, rmax=0;
    while ((r = l[i][j]) != 0){
        //printf("%d %d %d\n", i, j, r);
        if (a[i] == b[j]){
            f[r] = a[i];
            rmax++;
            i--;
            j--;
        }
        else if (l[i-1][j] == r){
                i--;
        }else j--;
    }

    fprintf(fout, "%d\n", rmax);
    for (int i=1; i<=l[m][n]; i++)
        fprintf(fout, "%d ", f[i]);

    fclose(fin);
    fclose(fout);
}
