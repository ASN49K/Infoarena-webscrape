#include <stdio.h>
#include <stdlib.h>

int n, m, a[1024], b[1024], c[1024][1024],d[1024], k;

void citire()
{
    FILE *fin;
    int i, j;

    fin=fopen("cmlsc.in", "r");
    fscanf(fin, "%d %d", &m, &n);

    for(i=1;i<=m;i++)
       fscanf(fin, "%d", &a[i]);
    for(j=1;j<=n;j++)
        fscanf(fin, "%d", &b[j]);

    fclose(fin);
}

int max(int x, int y)
{
    if(x>y) return x;

    return y;
}

void calculare()
{
    int i, j;

    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
          if(a[i]==b[j])
             c[i][j]=c[i-1][j-1]+1;
          else
             c[i][j]=max(c[i-1][j],c[i][j-1]);
}

void afisare()
{
    int i, j;
    FILE *fout;

    k=c[m][n];
    i=m;j=n;

    while(i)
       if(a[i]==b[j])
          {d[k--]=a[i]; i--; j--;}
       else if(c[i][j-1]>c[i-1][j])
              j--;
            else
              i--;

    fout=fopen("cmlsc.out", "w");
    fprintf(fout,"%d\n", c[m][n]);
    for(i=1;i<=c[m][n];i++)
       fprintf(fout,"%d ", d[i] );

    fclose(fout);

}

int main()
{
    citire();
    calculare();
    afisare();
    return 0;
}
