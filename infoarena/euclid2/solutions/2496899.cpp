#include<stdio.h>

int n,a,b;

int cmmdc(int a,int b){
	if(a==0) return b;
	return cmmdc(b%a,a);
}

void solve(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
}


int main(){
	solve();
}
