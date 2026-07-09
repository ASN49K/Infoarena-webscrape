#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *f=fopen("euclid2.in","rt"),*g=fopen("euclid2.out","wt");
   int a,b,r,t;
   fscanf(f,"%d",&t);
   for(i=0;i<t;++i){
   	fscanf(f,"%d %d",&a,&b);
      while(b!=0){
   		r=a%b;
      	a=b;
      	b=r;
   	}
   	fprintf(g,"%d\n",a);
   }
   fclose(f);
   fclose(g);
   return 0;
}
