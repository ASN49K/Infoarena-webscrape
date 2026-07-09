#include <stdio.h>
 
using namespace std;
int a,b,t,i,r;
int main(){
	freopen("euclid2.in","r",stdin); freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d,%d",&a,&b);
		r=a%b;
		while(r!=0){
			a=b;
			b=r;
			r=a%b;
		}
		printf("%d",a,"\n");
	}
	return 0;
}