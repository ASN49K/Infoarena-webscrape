#include <stdio.h>
#include <stdlib.h>

int mat[1025][1025], a[1024], b[1024], rez[1025];

int main(){
    FILE *fin, *fout;
    int n, m, i, j, nr;
    fin=fopen("cmlsc.in", "r");
    fout=fopen("cmlsc.out", "w");
    fscanf(fin, "%d%d", &n, &m);
    for(i=0;i<n;i++)
        fscanf(fin, "%d", &a[i]);
    for(i=0;i<m;i++)
        fscanf(fin, "%d", &b[i]);
    for(i=0;i<1025;i++)
        rez[i]=260;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i==0 || j==0)
                mat[i][j]=0;
            else{
                if(a[i-1]==b[j-1]){
                    mat[i][j]=mat[i-1][j-1]+1;
                    if(rez[mat[i][j]]==260)
                        rez[mat[i][j]]=a[i-1];
                }
                else{
                    if(mat[i][j-1]>mat[i-1][j])
                        mat[i][j]=mat[i][j-1];
                    else
                        mat[i][j]=mat[i-1][j];
                }
            }
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    fprintf(fout, "%d\n", mat[n][m]);
    for(i=1;i<=mat[n][m];i++)
        fprintf(fout, "%d ", rez[i]);
    fclose(fin);
    fclose(fout);

    return 0;
}
