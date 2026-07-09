#include<stdio.h>
using namespace std;
int cmmdc(int a,int b){
	int r,cmmdc;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	cmmdc=a;
	return cmmdc;
}	
int main(){
	int i,a,b,n;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
	    printf("%d\n", cmmdc(a,b));
	}
	return 0;
}