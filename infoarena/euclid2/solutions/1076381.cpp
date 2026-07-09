using namespace std;

#include<cstdlib>

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	int tt;
	scanf("%d",&tt);
	
	while(tt--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",gcd(a,b));
	}
	
	return 0;
}