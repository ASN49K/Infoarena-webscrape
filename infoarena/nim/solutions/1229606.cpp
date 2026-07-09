#include <iostream>
using namespace std;

int main(){
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	int t,n,a;
	scanf("%d",&t);
	for(;t--;){
		int res = 0;
		scanf("%d",&n);
		for(;n--;){
			scanf("%d",&a);
			res ^= a;
		}
		if(!res)
			printf("NU\n");
		else
			printf("DA\n");
	}

	return 0;
}