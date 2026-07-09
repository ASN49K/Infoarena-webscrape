#include <stdio.h>
#include <stdlib.h>

FILE *fin , *fout;

int v1[1024],v2[1024],raspuns[1024];
int d[1024][1024];

int main() {
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");

    int n,m,i,j,lung,k=0;

    fscanf(fin,"%d%d",&n,&m);
    for(i=0;i<n;i++) {
        fscanf(fin,"%d",&v1[i]);
    }
    for(j=0;j<m;j++) {
        fscanf(fin,"%d",&v2[j]);
    }
    if(v1[0]==v2[0]) {
        d[0][0]=1;
    }

    for(i=1;i<n;i++) {
        if(v1[i]==v2[0]) {
            d[i][0]=1;
        }
        else {
            d[i][0]=d[i-1][0];
        }
    }
    for(j=1;j<m;j++) {
        if(v2[j]==v1[0]) {
            d[0][j]=1;
        }
        else {
            d[0][j]=d[0][j-1];
        }
    }

    for(i=1;i<n;i++) {
        for(j=1;j<m;j++) {
            if(v1[i]==v2[j]) {
                d[i][j]=d[i-1][j-1]+1;
            }
            else {
                if(d[i-1][j]>d[i][j-1]) {
                    d[i][j]=d[i-1][j];
                }
                else {
                    d[i][j]=d[i][j-1];
                }
            }
        }
    }

    fprintf(fout,"%d\n",d[n-1][m-1]);

    lung=d[n-1][m-1];
    n--;
    m--;
    while(lung>0) {
        if(v1[n]==v2[m]) {
            raspuns[k]=v1[n];
            k++;
            n--;
            m--;
            lung--;
        }
        else {
            if(n>=1 && d[n-1][m]>=d[n][m-1]) {
                n--;
            }
            else {
                m--;
            }
        }
    }

    for(k--;k>=0;k--) {
        fprintf(fout,"%d ",raspuns[k]);
    }
    fprintf(fout,"\n");

    fclose(fin);
    fclose(fout);
    return 0;
}
