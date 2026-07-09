#include<stdio.h>
int o,N,M,best[1025][1025];
int v[1025],a[1025];
int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&N,&M);
int o=1;
for(int i=1;i<=N;++i)
scanf("%d",&v[i]);
for(int j=1;j<=M;++j)
scanf("%d",&a[j]);

for(int i=1;i<=N;++i)
    for(int j=1;j<=M;++j)
    {
    if(v[i]==a[j])
    best[i][j]=1+best[i-1][j-1];
    else
    {
        if(best[i-1][j]>best[i][j-1])
        best[i][j]=best[i-1][j];
        else
        best[i][j]=best[i][j-1];
    }

    }


printf("%d",best[N][M]);



return 0;
}
