#include <stdio.h>

long euclid(long a, long b){
long r;
while(r){
r=a%b;
a=b;
if(r==0) return b;
b=r;
}
return b;
}


int main(){
FILE *f=fopen("euclid2.in","r");
int T,i;
long a,b;
fscanf(f,"%d",&T);
FILE *g=fopen("euclid2.out","w");
for(i=0;i<T;i++){
  fscanf(f,"%ld",&a);
  fscanf(f,"%ld",&b);
  fprintf(g,"%ld\n",euclid(a,b));
}
fclose(g);
return 0;
}
