#include<stdio.h>
long gcd(long a,long  b){
     if (!b) return a;
     else return gcd(b, a % b)    ;
     }
int main(){
FILE *f,*g;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
long i,t,x,y;
fscanf(f,"%d",&t);
for(i=0;i<t;i++){
                 fscanf(f,"%d %d",&x,&y);
                 fprintf(g,"%d\n",gcd(x,y));
                 }
fclose(f);
fclose(g);
return 0;
}
