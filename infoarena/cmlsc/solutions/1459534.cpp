
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(void)
{
    FILE *in=0,*out=0;
    in=fopen("cmlsc.in","r");
    out=fopen("cmlsc.out","w");

    unsigned m,n,i,j,k;
    unsigned *x=0,*y=0,*z=0,**c=0;

    fscanf(in,"%u %u",&m,&n);

    x=(unsigned*)malloc(m*sizeof(unsigned));
    y=(unsigned*)malloc(n*sizeof(unsigned));

    for(i=0;i<m;++i)
        fscanf(in,"%u",x+i);

    for(i=0;i<n;++i)
        fscanf(in,"%u",y+i);

//alocare tablou in care fac rezolvarea
    c=(unsigned **)malloc((m+1)*sizeof(unsigned*));
    for(i=0;i<=m;++i)
        c[i]=(unsigned *)malloc((n+1)*sizeof(unsigned));
    if (!c)
    {
        fprintf(stderr,"Err - c table failed");
        exit(EXIT_FAILURE);
    }

//rezolvarea propriuzisa, determina in c[m][n] lungimea LCS
    for(i=1;i<=m;++i)
        c[i][0]=0;
    for(i=0;i<=n;++i)
        c[0][i]=0;

    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
        {
            if(x[i-1]==y[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>=c[i][j-1])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=c[i][j-1];
        }

    k=c[m][n];
    fprintf(out,"%u\n",k);

//afisare fiecare element din LCS
    i=m,j=n;

    z=(unsigned*)malloc(k*sizeof(unsigned));
    while(i&&j)
    {
        if(x[i-1]==y[j-1])
            {
                z[k-1]=x[i-1];
                --j;--i;--k;
            }
        else if(c[i-1][j]>=c[i][j-1])
            --i;
        else
            --j;
    }

    for(i=0;i<c[m][n];++i)
        fprintf(out,"%u ",z[i]);

    free(x);
    free(y);
    free(z);
    free(c);
    fclose(in);
    fclose(out);
    return 0;
}
