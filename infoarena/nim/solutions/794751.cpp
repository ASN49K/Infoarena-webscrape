#include<cstdio>

using namespace std;

int N;

int main(){

	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	
	scanf("%d",&N);
	
	while(N--){
		
		int nr;
		scanf("%d",&nr);
		
		int s=0;
		for(int i=1,p; i<=nr;++i){
			scanf("%d",&p);
			s^=p;
		}
		
		if(s)	printf("DA\n");
		else 	printf("NU\n");
	}
	
return 0;
}
