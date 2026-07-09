#include <stdio.h>

FILE *fin,*fout;
long a,b,t,i;

long euclid(long a,long b){
	long r;
	while(b){r=a %b;a=b;b=r;}
   return a;
}

int main(){
	fin=fopen("euclid2.in","r");
   fout=fopen("euclid2.out","w");
   fscanf(fin,"%ld",&t);
   for(i=1;i<=t;i++){
   	fscanf(fin,"%ld%ld",&a,&b);
      fprintf(fout,"%ld\n",euclid(a,b));
   }
   fclose(fin); fclose(fout);
   return 0;
}

