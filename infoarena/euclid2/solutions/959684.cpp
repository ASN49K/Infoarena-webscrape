#include<stdio.h>
int t,a,b,r,i;
FILE *f,*g;
int main(){
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&t);
    for(i=1;i<=t;i++){
        fscanf(f,"%d %d",&a,&b);
        r=a%b;
        while(r>0){
            a=b;
            b=r;
            r=a%b;
        }
        fprintf(g,"%d\n",b);
    }
    fclose(f);
    fclose(g);
    return 0;
}
