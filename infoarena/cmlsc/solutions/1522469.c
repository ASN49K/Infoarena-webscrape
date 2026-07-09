#include <stdio.h>
#include <stdlib.h>

int sir1[1024],sir2[1024],rez[1025],best[1024][1024];
int n,m,l;

void citire()
{
    int i;
    FILE *f=fopen("cmlsc.in","r");
    fscanf(f,"%d%d",&n,&m);
    for(i=0; i<n; i++)
        fscanf(f,"%d",&sir1[i]);
    for(i=0; i<m; i++)
        fscanf(f,"%d",&sir2[i]);
    fclose(f);
}

int max(int a,int b)
{
    return (a>b) ? a:b;
}

void rezolvare()
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(sir1[i]==sir2[j])
                best[i+1][j+1]=best[i][j]+1;
            else
                best[i+1][j+1]=max(best[i][j+1],best[i+1][j]);

    i=n;
    j=m;
    l=0;
    while(i>=0&&j>=0)
    {
        if(sir1[i-1]==sir2[j-1])
         {
             rez[l]=sir1[i-1];
             i--;
             j--;
             l++;
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
    int i;
    FILE *g=fopen("cmlsc.out","w");
    fprintf(g,"%d\n",l);
    for(i=l-1; i>=0; i--)
        fprintf(g,"%d ",rez[i]);
    fprintf(g,"\n");
    fclose(g);
}

int main()
{
    citire();
    rezolvare();
    afisare();
    return 0;
}
