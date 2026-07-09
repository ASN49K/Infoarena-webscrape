#include <stdio.h>
#include <stdlib.h>
FILE * out;
int ** s;
int ** LCS(int *a,int lengthA,int *b,int lengthB)
{
    int m=lengthA;
    int n=lengthB;
    int **c=(int **)calloc(m+1,sizeof(int*));
    s=(int **)calloc(m+1,sizeof(int*));
    for(int i=0; i<m+1; i++)
    {
        c[i]=(int *)calloc(n+1,sizeof(int));
        s[i]=(int *)calloc(n+1,sizeof(int));
    }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(a[i-1]==b[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                s[i][j]=7;
            }
            else
            {
                if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    s[i][j]=8;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    s[i][j]=6;
                }
            }

        }
    return c;
}
void LCS_Print(int *a,int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(s[i][j]==7)
    {
        LCS_Print(a,i-1,j-1);
        fprintf(out,"%d ",a[i-1]);
    }
    else
    {
        if(s[i][j]==8)
        {
            LCS_Print(a,i-1,j);
        }
        else
        {
            LCS_Print(a,i,j-1);
        }
    }
}
int main()
{
    FILE * in = fopen("cmlsc.in","r");
    out = fopen("cmlsc.out","w");
    int m,n;
    fscanf(in,"%d %d",&m,&n);
    int * a=(int *)calloc(m,sizeof(int));
    int * b=(int *)calloc(n,sizeof(int));
    for(int i=0; i<m; i++)
    {
        fscanf(in,"%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        fscanf(in,"%d",&b[i]);
    }
    int **c=LCS(a,m,b,n);
    fprintf(out,"%d\n",c[m][n]);
    LCS_Print(a,m,n);
    free(c);
    free(s);
    free(a);
    free(b);
    fclose(in);
    fclose(out);
    return 0;
}
