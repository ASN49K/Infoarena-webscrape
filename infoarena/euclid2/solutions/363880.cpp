#include <cstdio>

int a,b,n;

int cmmdc(int a,int b){
	if(!b)return a;
	else return cmmdc(a%b,b);
}
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%u",&n);
	for(int i=0;i<n;i++){
		scanf("%u %u",&a,&b);
		printf("%u\n",cmmdc(a,b));
	}

	return 0;
}