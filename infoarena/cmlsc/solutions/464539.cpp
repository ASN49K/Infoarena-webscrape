#include <cstdio>
#include <iostream>
using namespace std;
#define DN 1025

int sir1[DN],sir2[DN],n,m,d[DN][DN],nre,cmlsc[DN];

int main()
{
    int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m );
	for(i=1; i<=n; i++) scanf("%d",&sir1[i] );
	for(i=1; i<=m; i++) scanf("%d",&sir2[i] );
	for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(sir1[i]==sir2[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]= max(d[i][j-1],d[i-1][j]);
    for(i=n,j=m; i && j; )
        if(sir1[i]==sir2[j]) cmlsc[++nre]=sir1[i],--i,--j;
        else if(d[i-1][j] < d[i][j-1]) --j;
        else --i;
    //afisare
    printf("%d\n", nre);
    for(i=nre; i; i--) printf("%d ",cmlsc[i]);
	return 0;
}

