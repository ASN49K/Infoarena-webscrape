#include <cstdio>

FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");
int T,a,b;
void euclid2(){
	
	while(a!=b){
		if(a>b){
			a-=b;
		}
		if(a<b){
			b-=a;
		}
	}
	fprintf(g,"%d\n",a);
}

int main(){
	
	fscanf(f,"%d",&T);
	for(int i =1;i<=T;i++){
		fscanf(f,"%d %d",&a,&b);
		euclid2();
	}
	
	
	
	fclose(g);
	fclose(f);
	return 0;
}