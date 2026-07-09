#include<cstdio>
int main(){
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int x,s=0;
		while(n--){
			scanf("%d",&x);
			s^=x;
		}
		if(s==0)
			puts("NU");
		else
			puts("DA");
	}
	return 0;
}
