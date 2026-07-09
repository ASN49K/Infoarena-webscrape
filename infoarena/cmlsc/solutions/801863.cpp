#include<stdio.h>
int m,n,a[1025],b[1025],best[1025][1025],sol[1025],max;
FILE *fin,*fout;

void citire()
{
    fin=fopen("cmlsc.in","r");
    fscanf(fin,"%d %d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        fscanf(fin,"%d",&a[i]);
    }
    for(int j=1;j<=n;j++)
    {
        fscanf(fin,"%d",&b[j]);
    }
}

void cmlsc()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                best[i][j]=best[i-1][j-1]+1;
            }
            else
            if(best[i-1][j]>best[i][j-1])
                best[i][j]=best[i-1][j];
                else
                    best[i][j]=best[i][j-1];
        }
    }
}

void reconst()
{
int i=m,j=n;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
           // printf("%d    %d\n",i,j);
            sol[best[i][j]]=a[i];
            i--;
            j--;
        }
        else
        if(best[i-1][j]>best[i][j-1])
            i--;
            else
                j--;
    }
}

void afisare()
{
    fout=fopen("cmlsc.out","w");
    fprintf(fout,"%d\n",best[m][n]);
    for(int i=1;i<=best[m][n];i++)
    {
        fprintf(fout,"%d ",sol[i]);
    }
}

int main()
{
    citire();
    cmlsc();
    reconst();
    afisare();
    return 0;
}
