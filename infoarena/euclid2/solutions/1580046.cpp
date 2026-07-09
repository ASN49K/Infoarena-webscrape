#include<stdio.h>

int T,a,b;

int euclid(int a,int b){
	if(!b)
		return a;

	return euclid(b,a%b);
}

int main(){

	freopen("euclid.in","r",in);
	freopen("euclid.out","w",out);

	scanf("%u",T);

	for(;T>0;T--){
		scanf("%u %u",a,b);

		printf("%u\n",euclid(a,b));
		
}

return 0;

}