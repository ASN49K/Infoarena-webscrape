#include <cstdio>
#define max(a, b) ((a>b) ? a:b)

using namespace std;

const int Nmax=1025;
int a[Nmax], b[Nmax], m, n, c[Nmax][Nmax], sir[Nmax], k=0;

void cmlsc(int m, int n){
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j){
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j], c[i][j-1]);
		}
}

int main(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for(int i=1; i<=m; ++i)
		scanf("%d", &a[i]);
	for(int i=1; i<=n; ++i)
		scanf("%d", &b[i]);
	cmlsc(m, n);
	int i=m, j=n;
	while(i>0 && j>0){
		if(a[i]==b[j]){
			sir[++k]=a[i];
			--i;
			--j;	
		}
		else if(c[i-1][j]>c[i][j-1])
			i--;
		else
			j--;
	}
	printf("%d\n", k);
	for(i=k; i>0; --i)
		printf("%d ", sir[i]);
	return 0;
}
