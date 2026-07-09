#include<stdio.h>
FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
long int t;


void get_number(long int a,long int b){
long int r=0;
	r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	fprintf(g,"%ld\n",b);

}

void read(){
long int i;
long int x,y;
	fscanf(f,"%ld\n",&t);
	for(i=1; i<=t; i++){
		fscanf(f,"%ld %ld\n",&x,&y);
		get_number(x,y);
	}
}

int main(){
	read();

return 0;
}