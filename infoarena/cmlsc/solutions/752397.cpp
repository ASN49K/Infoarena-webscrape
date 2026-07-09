#include <cstdio>
#include <algorithm>
using namespace std;
#define l 10005

int sol[l],a[l],b[l],nume[l][l];

int main (){
	int n,m,i,j,sz=0;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;++i)
		scanf("%d", &a[i]);
	for(i=1;i<=m;++i)
		scanf("%d", &b[i]);
	
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			if(a[i]==b[j])
				nume[i][j]=nume[i][j]+1;
			if(a[i]!=b[j])
				nume[i][j]=max(nume[i-1][j],nume[i][j-1]);
		}
				
	
	for(i=n,j=m;i&&j;){
		if(a[i]==b[j]){
			sol[++sz]=a[i];
			--i;
			--j;
		}
		else{
			if(nume[i-1][j]>nume[i][j-1])--i;
			else --j;
		}
	}
	printf("%d\n",sz);
	
	for(i=sz;i;--i)
		printf("%d ",sol[i]);
}
	
		