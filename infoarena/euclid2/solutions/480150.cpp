#include <stdio.h>



int euclid(int a,int b){
int temp;

if(b>a){temp=a;a=b;b=temp;}
	if(a%b==0){return b;}

	else {
	
	return euclid(b,a%b);

	}


}


int main(){
int t,a,b,i;

freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%d",&t);

for(i=1;i<=t;i++){
scanf("%d %d",&a,&b);

printf("%d\n",euclid(a,b));


}




return 0;
}