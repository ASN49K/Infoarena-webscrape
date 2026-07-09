#include<stdio.h>
#include<stdlib.h>

int euclid(int a, int b){
	if(b==0) return a;
	else return euclid(b,a%b);
}

void euclid2(FILE *f, int n){
	FILE *out = fopen("euclid2.out","w");
	int i,a,b;
	for(i=0; i<n; i++){
		fscanf(f,"%d%d",&a,&b);
		fprintf(out,"%d\n",euclid(a,b));
	}
	fclose(out);
}


int main(){
	FILE *f = fopen("euclid2.in","r");
	int n;
	fscanf(f,"%d",&n);
	euclid2(f,n);
	fclose(f);
	getchar();
	return 0;
	system("pause");
}
