#include <stdio.h>
#include <stdlib.h>
int d[1025][1025],a[1025],b[1025],sol[1025];
int main()
{
    FILE *fin,*fout;
    int n,m,i,j,e;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
            {
                if(d[i-1][j]>d[i][j-1])
                    d[i][j]=d[i-1][j];
                else
                    d[i][j]=d[i][j-1];
            }
    i=n;
    j=m;
    e=0;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            sol[e]=a[i];
            e++;
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]>d[i][j-1])
               i--;
            else
               j--;
        }
    }
    fprintf(fout,"%d\n",d[n][m]);
    for(e--;e>=0;e--)
        fprintf(fout,"%d ",sol[e]);
    fclose(fin);
    fclose(fout);
    return 0;
}
