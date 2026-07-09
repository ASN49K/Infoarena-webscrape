#include <stdio.h>

int main(){
	
	int a,b,r;
	scanf("%d%d",&a,&b);

	r = a % b;
	while(r){
		a = b;
		b = r;
		r = a % b;
	}
	printf("Cmmdc:%d\n",b);
	return 0;
}