#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a,int b){
return (a%b)?cmmmdc(b,a%b),b;
}

int main(){

FILE *fp_r,*fp_w;
int N;
int a,b;

fp_r=fopen("euclid2.in","r");
fp_w=fopen("euclid2.out","w");
fscanf(fp_r,"%d",&N);
for(i=0;i<N;i++){
   fscanf(fp_r,"%d %d",&a,&b);
   if(a==0 || b==0)
     fprintf(fp_w,"%d",a+b);
   else
     fprintf(fp_w,"%d\n",cmmdc(a,b));
}

return 0;
}