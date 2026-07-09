#include <stdio.h>

FILE *fin,*fout;

int a[1030],b[1030],n,m,x[1030][1030];

void citire()
{
    fin=fopen("cmlsc.in","r");
    fscanf(fin,"%d %d",&m,&n);
    for (int i=1; i<=n; i++)
        fscanf(fin,"%d",&a[i]);
    for (int j=1; j<=m; j++)
        fscanf(fin,"%d",&b[j]);
    fclose(fin);
}

int maxim(int a,int b)
{
    if (a>b)
        return a;
    return b;
}

void prel()
{
    fout=fopen("cmlsc.out","w");
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i+1]==b[j+1])
            {
                x[i+1][j+1]=1+x[i][j];
            }
            else
                x[i+1][j+1]=maxim(x[i+1][j],x[i][j+1]);
    fprintf(fout,"%d\n",x[n][m]);
    int ii=n,jj=m,r[1030];
    while (x[ii][jj] > 0)
    {
        if (a[ii]==b[jj])
        {
            r[x[ii][jj]]=a[ii];
            --ii;
            --jj;
        }
        else
        {
            if (x[ii][jj]==x[ii-1][jj])
                --ii;
            else
                --jj;
        }
    }
    for (int q=1; q<=x[n][m]; q++)
        fprintf(fout,"%d ",r[q]);
    fprintf(fout,"\n");
}

int main()
{
    citire();
    prel();
    fclose(fout);
    return 0;
}
