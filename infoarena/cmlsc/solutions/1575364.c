#include <cstdio>

#define maxim(a,b) ((a > b) ? a : b)
#define NMax 1024
#define FOR(i,a,b) for(i=a;i<=b;++i)

FILE *f,*g;

int n,m,a[NMax],b[NMax],d[NMax][NMax],sir[NMax],bst;

int main()
{
    f=fopen("sir.in","r");
    g=fopen("sir.out","w");

    int i,j;
    fscanf(f,"%d%d",&m,&n);
    FOR(i,1,m)
        fscanf(f,"%d",&a[i]);
    FOR(i,1,n)
        fscanf(f,"%d",&b[i]);
    FOR(i,1,m)
        FOR(j,1,n)
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=maxim(d[i-1][j-1],d[i][j-1]);
    for(i=m,j=n;i; )
        if(a[i]==b[j]) sir[++bst]=a[i],--i,--j;
        else if(d[i-1][j]<d[i][j-1]) --j;
        else --i;
    fprintf(g,"%d\n",bst);
    for(i=bst;i;--i)
        fprintf(g,"%d ",sir[i]);
    return 0;
}
