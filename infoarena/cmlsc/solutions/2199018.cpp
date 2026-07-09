#include <stdio.h>


int m,n,p,a[1026],b[1026],c[1026][1026];
/*
int cml(int i, int j, int p)
{
    int p1,p2;
    if(i>m || j>n)
        return p;
    if(a[i]==b[j])
        return cml(i+1,j+1,p+1);
    else
    {
        p1=cml(i+1,j,p);
        p2=cml(i,j+1,p);
        if(p1>p2)
            return p1;
        else
            return p2;
    }

}

*/

int main()
{
    int i,j;
    FILE *f,*g;

    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");

    fscanf(f,"%d%d",&m,&n);

    for(i=1;i<=m;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&b[i]);

    for(i=m;i>=1;i--)
        for(j=n;j>=1;j--)
        {
            if(c[i][j+1]<c[i+1][j])
                c[i][j]=c[i+1][j];
            else
                c[i][j]=c[i][j+1];
            if(a[i]==b[j])
                 c[i][j]++;
        }

    fprintf(g,"%d\n",c[1][1]);
    for(i=1,j=1;i<=m,j<=n;)
    {
        if(a[i]==b[j])
        {
            fprintf(g,"%d ",a[i]);
            i++;j++;
        }
        else
           if(c[i+1][j]>c[i][j+1])
             i++;
           else
             j++;
    }
    fclose(f);
    fclose(g);


}
