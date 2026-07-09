#include <cstdio>
#include <cstdlib>
using namespace std;
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
void readvector(int v[],int n) {
	for(int i=0;i<n;i++)
		scanf("%d",&v[i])	
}
int main() {
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	int v[1024];
	int w[1024];
	int resp[1024];
	readvector(v,m);
	readvector(w,n);
	int mx=0;
	bool ok=true;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			if(v[i]==w[j]) {
				res[mx++]=v[i];
				break;
			}
		}
	}
	printf("%d\n",mx);
	for(int i=0;i<mx;i++)
			printf("%d ",res[i]);
}