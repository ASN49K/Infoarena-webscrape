#include<stdio.h>
void solve(){
	int n,i,x,r;
	scanf("%d",&n);
	scanf("%d",&r);
	for(i=1;i<n;++i){
		scanf("%d",&x);
		r^=x;
	}
	if(!r)
		printf("NU\n");
	else
		printf("DA\n");
}
int main(){
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(;t;--t)
		solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
