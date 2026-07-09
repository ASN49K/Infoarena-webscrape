#include<cstring>
#include<iostream>
#include<cstdio>

int main()
{
    FILE* fin=fopen("cmlsc.in","r"),
            *fout=fopen("cmlsc.out","w");
    int n,m,i,j;
    short D[1030][1030],a[1030],b[1030];
    fscanf(fin,"%d %d",&n,&m);
    for(i=1;i<=n;++i)
        fscanf(fin,"%d",&a[i]);
    for(j=1;j<=m;++j)
        fscanf(fin,"%d",&b[j]);

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=std::max(D[i-1][j],D[i][j-1]);

    int len=0;
    short sir[1030];
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
            sir[len++]=a[i],--i,--j;
        else if(D[i-1][j]<D[i][j-1])
            --j;
        else
            --i;
    }

    fprintf(fout,"%d\n",len);

    for(i=len-1;i>=0;--i)
    {
        fprintf(fout,"%d ",sir[i]);
    }
    putc('\n',fout);
    return 0;
}
