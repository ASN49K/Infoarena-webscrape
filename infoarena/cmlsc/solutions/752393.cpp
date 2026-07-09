#include <cstdio>
#include <algorithm>
using namespace std;
#define l 1029
int a[l],b[l],sol[l],nume[l][l];
int main () {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i,j,sz=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;++i){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i]==b[j]){
				nume[i][j]=nume[i-1][j-1]+1;
			}
			else{
				nume[i][j]=max(nume[i-1][j],nume[i][j-1]);
			}
		}
	}
	for(i=n,j=m;i&&j;){
		if(a[i]==b[j]){
			sol[++sz]=a[i];
			--i;--j;
		}
		else{
			if(nume[i-1][j]>nume[i][j-1]){
				--i;
			}
			else{
				--j;
			}
		}
	}
	printf("%d\n",nume[n][m]);
	for(i=sz;i;--i){
		printf("%d ",sol[i]);
	}
	return 0;
}
