#include <stdio.h>
#include <stdlib.h>

int *a;
int *b;
int **mat;
int *sol;
int m,n,l=0;

void citire()
{
    FILE *f=fopen("cmlsc.in","r");
    int i;

    fscanf(f,"%d%d",&m,&n);

    a=(int*)malloc((m+1)*sizeof(int));
    b=(int*)malloc((n+1)*sizeof(int));

    mat=(int**)malloc((n+1)*sizeof(int*));

    for(i=0;i<=n;i++)
        *(mat+i)=(int*)malloc((m+1)*sizeof(int));

    if (m>n)
        sol=(int*)malloc((m+1)*sizeof(int));
    else
        sol=(int*)malloc((n+1)*sizeof(int));

    for (i=1;i<=m;i++)
        fscanf(f,"%d",&a[i]);
    for (i=1;i<=n;i++)
        fscanf(f,"%d",&b[i]);

    fclose(f);
}

void rezolvare()
{
    int i,j;

    for (i=0;i<=n;i++)
        for (j=0;j<=m;j++)
        mat[i][j]=0;

    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j])
                mat[j][i]=1+mat[j-1][i-1];
            else
                mat[j][i]=mat[j-1][i]>mat[j][i-1]?mat[j-1][i]:mat[j][i-1];

    i=n;
    j=m;
    while(i>0)
        {
            if (a[j]==b[i])
            {
                sol[l++]=a[j];
                i--;
                j--;
            }
            else
                if (mat[i-1][j]<mat[i][j-1])
                   j--;
                else i--;
        }
}

void afisare()
{
    FILE *g=fopen("cmlsc.out","w");
    int i;

    fprintf(g,"%d\n",l);

    for (i=l-1;i>=0;i--)
        fprintf(g,"%d ",sol[i]);
    fclose(g);
}

int main()
{
    int i,j;
    citire();
    rezolvare();
     /*for (i=0;i<=n;i++)
       {
           for (j=0;j<=m;j++)
                printf("%d ",mat[i][j]);
            printf("\n");
       }
    */
    afisare();
    return 0;
}
