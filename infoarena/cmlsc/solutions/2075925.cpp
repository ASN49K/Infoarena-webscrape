#include <bits/stdc++.h>

#define MaxN 1030
#define INF 2140000000
#define MOD 1999999973

using namespace std;

FILE*IN,*OUT;

int N,M,v1[MaxN],v2[MaxN],d[MaxN][MaxN],out[MaxN];
int main()
{
    IN=fopen("cmlsc.in","r");
    OUT=fopen("cmlsc.out","w");

    fscanf(IN,"%d%d",&N,&M);

    for(int i=1;i<=N;i++)
        fscanf(IN,"%d",&v1[i]);
    for(int i=1;i<=M;i++)
        fscanf(IN,"%d",&v2[i]);

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            d[i][j]=d[i-1][j];
            if(d[i][j]<d[i][j-1])
                d[i][j]=d[i][j-1];
            if(v1[i]==v2[j]&&d[i][j]<1+d[i-1][j-1])
                d[i][j]=1+d[i-1][j-1];
        }
    int x=N,y=M;
    while(x>0&&y>0)
    {
        if(d[x][y]==d[x][y-1])y--;
        else if(d[x][y]==d[x-1][y])x--;
        else
        {
            out[d[x][y]]=v1[x];
            x--,y--;
        }
    }
    fprintf(OUT,"%d\n",d[N][M]);
    for(int i=1;i<=d[N][M];i++)
        fprintf(OUT,"%d ",out[i]);
    return 0;
}
