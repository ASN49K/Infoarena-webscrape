#include<cstdio>
using namespace std;
int main ()
{
	int a,b,t,r;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d%d",&a,&b);
		r=a%b;
		while(r){
			a=b;
			b=r;
			r=a%b;
		}
		printf("%d\n",b);
	}
	return 0;
}
