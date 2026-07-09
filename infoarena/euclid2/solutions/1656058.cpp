#include <stdio.h>

int eucl(int a , int b){
	if (b==0) return a;
	else return eucl(b , a%b);

}

int main(){
	int a ,b;
	FILE *f1=fopen("euclid2.in","r");
	FILE *f2=fopen("euclid2.out","w");
	int n;
	fscanf(f1,"%d", &n);
	while (n >0){
		fscanf(f1,"%d %d", &a , &b);
		fprintf(f2,"%d\n", eucl(a,b));
		n--;
	 }
	fclose(f1);
	fclose(f2);
}