#include<cstdio>
long a,b,c,t;
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&t);
	for(;t>0;t--){
		scanf("%ld%ld",&a,&b);
		while(b!=0){
			c=a%b;
			a=b;
			b=c;
		}
		printf("%ld\n",a);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
