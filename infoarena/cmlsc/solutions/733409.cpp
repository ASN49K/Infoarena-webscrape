#include<stdio.h>
#include<algorithm>
using namespace std;
int m,n,v[1025],u[1025],i,j,sol[1025][1025];
int main() {
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&u[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v[i]==u[j])
				sol[i][j]=sol[i-1][j-1]+1;
			else
				sol[i][j]=max(sol[i][j-1],sol[i-1][j]);
	printf("%d",sol[n][m]);
	return 0;
}
