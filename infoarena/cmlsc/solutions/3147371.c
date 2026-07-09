#include <stdio.h>
#include <stdlib.h>

#define max(x,y) ((x<y) ? y : x)

int m,n,x[1024],y[1024],c[1024][1024],sir[1024];

int main() {

    FILE* in= fopen("cmlsc.in","r");
    if(!in)
        return -1;

    FILE* out= fopen("cmlsc.out","w");
    if(!out)
        return -2;

    fscanf(in,"%d %d",&m,&n);
    int i,j;
    for (i=1;i<=m;i++) {
        fscanf(in, "%d", x + i);
    }

    for (j=1;j<=n;j++) {
        fscanf(in, "%d", y + j);
    }

    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++){
            if(x[i]==y[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]= max(c[i-1][j],c[i][j-1]);
        }

    int dim=c[m][n];
    fprintf(out,"%d\n" ,dim);

    while (i&&j){
        if(x[i]==y[j]){
            sir[dim--]=x[i];
            --i;
            --j;
        }
        else
            if(c[i-1][j]<c[i][j-1])
                --j;
            else
                --i;
    }
    for(i=0;i<c[m][n];i++)
        fprintf(out,"%d ",sir[i]);

    return 0;
}
