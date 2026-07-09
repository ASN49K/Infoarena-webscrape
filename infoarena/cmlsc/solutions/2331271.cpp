#include <cstdio>
#include <iostream>

using namespace std;
FILE *f,*g;
int a[1050],b[1050],d[1050][1050];

void tipar(int m, int n, int lg)///sirul in ordine lexicografica
{
    int nr=10,l,c;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                if(d[i][j]==lg && a[i]==b[j] && nr>a[i])
                    nr=a[i],l=i,c=j;
        if(nr!=10)
        {
            fprintf(g,"%d ",a[l]);
            tipar(l-1,c-1,d[l][c]-1);
        }
}
void dinamica(int m,int n)
{
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
}
int main()
{    int m,n;
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    fscanf(f,"%d %d",&m,&n);
    for(int i=1;i<=m;++i)
        fscanf(f,"%d",&a[i]);
    for(int i=1;i<=n;++i)
        fscanf(f,"%d",&b[i]);
    for(int i=1;i<=m/2;++i)
        swap(a[i],a[m-i+1]);
    for(int i=1;i<=n/2;++i)
        swap(b[i],b[n-i+1]);
    dinamica(m,n);
    /*for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
            fprintf(g,"%d",d[i][j]);
        fprintf(g,"\n");
    }*/
    fprintf(g,"%d\n",d[m][n]);
    tipar(m,n,d[m][n]);

    fclose(f);
    fclose(g);
    return 0;
}
