#include<stdio.h>
int cmmdc( int a,int b){
	int r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main(){
	int a,b,t;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while(t--){//verifica daca t e diferit de 0 si scade 1 din el
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
