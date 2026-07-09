#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f,*g;
    int m,n,a[1025],b[1025],l[1025][1025],i,j,k;
    int s[1025];
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");

    fscanf(f,"%d%d",&m,&n);
    for(i=1;i<=m;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&b[i]);

    for(i=0;i<=m;i++) l[i][0]=0;
    for(i=0;i<=n;i++) l[0][i]=0;

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=(l[i-1][j]>l[i][j-1]?l[i-1][j]:l[i][j-1]);

    k=0; i=m; j=n;
    while(i)
        if(a[i]==b[j])
        {
            s[++k]=a[i];
            i--;
            j--;
        }
        else if (l[i-1][j]<l[i][j-1])
                j--;
             else
                i--;

    fprintf(g,"%d\n",k);
    for(i=k;i>0;i--)
        fprintf(g,"%d ",s[i]);
    fprintf(g,"\n");

    fclose(f);
    fclose(g);
    return 0;
}
