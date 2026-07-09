#include <iostream>
#include <stdio.h>
using namespace std;
FILE *in,*out;
int n,m,i,j,k;
int a[257],b[257],v[257],sol[257][257];
int subsir( int i, int j)
{
    if(sol[i][j]!=-1)
        return sol[i][j];
    else
    {
        if(a[i]==b[j])
        {
            sol[i][j]=1+subsir(i-1,j-1);
            return sol[i][j];
        }

        else
        {
            if(subsir(i-1,j)>subsir(i,j-1))
            {
                sol[i][j]=subsir(i-1,j);
                return sol[i][j];
            }
            else
            {
                sol[i][j]=subsir(i,j-1);
                return sol[i][j];
            }

        }
    }
}
int main()
{
    in=fopen("cmlsc.in","r");
    out=fopen("cmlsc.out","w");
    fscanf(in,"%d%d",&m,&n);
    for(i=1; i<=m; i++)
        fscanf(in,"%d",&a[i]);
    for(i=1; i<=n; i++)
        fscanf(in,"%d",&b[i]);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            sol[i][j]=-1;
    subsir(m,n);

    fprintf(out,"%d\n",sol[m][n]);
    i=m;
    j=n;
    while(sol[i][j]!=0)
    {
        if(sol[i-1][j]<sol[i][j] && sol[i][j-1]<sol[i][j])
        {
            v[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(sol[i-1][j]==sol[i][j-1])
                i--;
            else
            {
                if(sol[i-1][j]==sol[i][j])
                    i--;
                if(sol[i][j-1]==sol[i][j])
                    j--;
            }
        }

    }
    for(i=k;i>0;i--)
        fprintf(out,"%d ",v[i]);



    return 0;
}
