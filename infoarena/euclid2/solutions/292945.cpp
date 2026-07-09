#include<cstdio>

int N;

int main(){
	int i,j,r;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%d",&N);
	for(;N--;){
		scanf("%d %d",&i,&j);
		do{
			r=i%j;
			i=j;
			j=r;
		}while(r>0);

		printf("%d\n",i);
	}
	return 0;
}
