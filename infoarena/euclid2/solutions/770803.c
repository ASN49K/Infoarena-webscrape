#include<stdio.h>
long int euclid(long int a,long int b)
{
if (!b) return a;
return euclid(b, a % b);
}
int main(){
    FILE *f=fopen("euclid2.in","r");
    FILE*fp=fopen("euclid2.out","w");
long int a,b,aux,r,t,i;
fscanf(f,"%ld",&t);
for(i=0;i<t;i++){
fscanf(f,"%ld",&a);
fscanf(f,"%ld",&b);
fprintf(fp,"%ld\n",euclid(a,b));
}
        fclose(f);
        fclose(fp);
return 0;
}
