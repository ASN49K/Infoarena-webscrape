#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
FILE*in=fopen("cmlsc.in","r");
FILE*out=fopen("cmlsc.out","w");
int n,m,v[1025],w[1025],d[1025][1025],sol[1025],pos=0;
int main()
{

    fscanf(in,"%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        fscanf(in,"%d",&v[i]);
    for(int i=1;i<=m;++i)
        fscanf(in,"%d",&w[i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(v[i]==w[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
    while(n && m)
    {
        if(v[n]==w[m])
        {
            sol[++pos]=v[n];
            --n;
            --m;
        }
        else
            if(d[n-1][m]>d[n][m-1])
                --n;
            else
                --m;
    }
    fprintf(out,"%d\n",pos);
    for(int i=pos;i>0;--i)
        fprintf(out,"%d ",sol[i]);

fclose(in);
fclose(out);
return 0;
}



