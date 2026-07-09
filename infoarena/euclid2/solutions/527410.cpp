#include <stdio.h>

typedef int tipus;

tipus t,a,b;

tipus euclid(tipus a,tipus b){
	
	if(a%b==0){return b;}
	else{ return euclid(b,a%b);}
	
}


int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	tipus i;
	
	scanf("%d",&t);
	
	for(i=1;i<=t;i++){
		scanf("%d %d",&a,&b);
		
		prinf("%d",euclid(a,b));
	}

	
	return 0;}