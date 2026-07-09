#include <stdio.h>

using namespace std;

FILE*f=fopen("submultimi.in","r");
FILE*g=fopen("submultimi.out","w");

int main()
{
    int n,m,i,j;
    fscanf(f,"%d",&n);
    m=(1<<n)-1;
    for (i=1;i<=m;i++){
        for (j=0;1<<j<=i;j++)
            if (1<<j&i) fprintf(g,"%d ",j+1);
        fprintf(g,"\n");
    }
    fclose(f);
    fclose(g);
    return 0;
}
