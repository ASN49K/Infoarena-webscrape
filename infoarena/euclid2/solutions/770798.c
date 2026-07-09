#include<stdio.h>
int main(){
    FILE *f=fopen("euclid2.in","r");
    FILE*fp=fopen("euclid2.out","w");
long int a,b,aux,r,t,i;
fscanf(f,"%ld",&t);
for(i=0;i<t;i++){
fscanf(f,"%ld",&a);
fscanf(f,"%ld",&b);
while (a!=b ){
if(a>b) a=a-b;
        else b=b-a;
            }
            if(b!=1) fprintf(fp,"%ld\n",b);
                else fprintf(fp,"1\n");
}
        fclose(f);
        fclose(fp);
return 0;
}
