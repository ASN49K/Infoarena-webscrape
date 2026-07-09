#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024
int v[MAXN+1],b[MAXN+1],mat[MAXN+2][MAXN+2],sol[MAXN];
int main() {
    FILE *fin,*fout;
    int n,m,i,j,l,c,max,len;
    fin=fopen("cmlsc.in","r");
    fscanf(fin,"%d%d",&n,&m);
    for(i=1; i<=n; i++) {
        fscanf(fin,"%d",&v[i]);
    }
    for(i=1; i<=m; i++) {
        fscanf(fin,"%d",&b[i]);
    }
    fclose(fin);
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(v[i]==b[j]) {
                mat[i][j]=mat[i-1][j-1]+1;
            } else {
                if(mat[i-1][j]>mat[i][j-1]) {
                    mat[i][j]=mat[i-1][j];
                } else {
                    mat[i][j]=mat[i][j-1];
                }
            }
        }
    }
    max=-1;
    l=c=0;
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(mat[i][j]>max) {
                max=mat[i][j];
                l=i;
                c=j;
            }
        }
    }
    len=0;
    while(l>0&&c>0) {
        if(v[l]==b[c]) {
            sol[len++]=v[l];
            l--;
            c--;
        } else {
            if(mat[l-1][c]>mat[l][c-1]) {
                l--;
            } else {
                c--;
            }
        }
    }
    fout=fopen("cmlsc.out","w");
    fprintf(fout,"%d\n",max);
    for(i=len-1; i>=0; i--) {
        fprintf(fout,"%d ",sol[i]);
    }
    fclose(fout);
    return 0;
}
