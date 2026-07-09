#include<stdio.h>

int t;
int euclid(int x,int y){
if(!y) return x;
return euclid(y,x%y);
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	for(scanf("%d\n",&t);t;t--){
		int x,y;
		scanf("%d %d\n",&x,&y);
		printf("%d\n",euclid(x,y));
  	}
fclose(stdout);
return 0;
}