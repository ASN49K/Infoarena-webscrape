#include<stdio.h>
#include<algorithm>
using namespace std;
int m,n,v[1025],u[1025],i,j,sol[1025][1025],a[1025];
// backtrack

int backtrack(int i, int j, int &length) {
    if (i==0 || j==0)
        return 0;
    else if  (v[i]==u[j]) {
		length++;
		a[length]=i;
        return backtrack(i-1, j-1,length);
	}
    else
        if (sol[i][j-1]>sol[i-1][j]) 
            return backtrack(i, j-1,length);
        else
            return backtrack(i-1, j,length);
}

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
	printf("%d\n",sol[n][m]);
	int length=0;
	backtrack(n,m,length);
	for(i=length;i>=1;i--) 
		printf("%d ",v[a[i]]);
	printf("\n");
	return 0;
}
