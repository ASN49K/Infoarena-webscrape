#include<stdio.h>

int cmmdc(int a,int b){
    int t;
    while(b != 0){
	t = b;
	b = a % b;
	a = t;
    }
    return a;
}

int main(){
    FILE *f,*g;
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    int n,a,b,i,t;
    fscanf(f,"%d",&n);
    for(i = 0;i < n;i++){
	fscanf(f,"%d",&a);
	fscanf(f,"%d",&b);
	t = cmmdc(a,b);
	fprintf(g,"%d\n",t);
    }
    fprintf(g,"\n");
    fclose(f);
    fclose(g);	
    return 0;
}
	