#include <stdio.h>
int cmmdc(int a, int b){
    int r;
    do{
        r=a%b;
        a=b;
        b=r;
    } while (r!=0);
    return a;
}
int main(){
    int a,b,n,i;
    FILE *f,*g;
    f=fopen("euclid2.in","rt");
    g=fopen("euclid2.out","wt");
    fscanf(f,"%d\n",&n);
    for(i=0;i<n;i++){
    	fscanf(f,"%d %d\n",&a,&b);
    	fprintf(g,"%d\n",cmmdc(a,b));
    }
    fclose(f);
    fclose(g);
    printf("Succes\n");
    return 0;
}
