#include <cstdio>
int rezolva(int a,int b){
	if (b==0)
		return a;
    else 
		return rezolva(b,a%b);
}
int main(){
	int t,i;
	int a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	//for (i=1;i<=t;++i){
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",rezolva(a,b));
	}
	return 0;
}
