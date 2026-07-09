#include<fstream>

using namespace std;

int main(){
	freopen("nim.in","r",stdin); freopen("nim.out","w",stdout);
	int t,n,xorSum,x;
	scanf("%i",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		xorSum=0;
		while(n--){
			scanf("%d",&x);
			xorSum=xorSum^x;
		}
		if(xorSum==0) printf("NU\n");
		else          printf("DA\n");
	}
	
	return 0;
}
