#include <cstdio>
using namespace std;

int n,a,b,r,i;

int main(){
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&n);
	
	for(i=1;i<=n;++i){
		scanf("%d%d",&a,&b);
		r=1;
		while (r){
			r=a%b;
			a=b;
			b=r;
			}
		printf("%d\n",a);
		}
	return 0;
}
