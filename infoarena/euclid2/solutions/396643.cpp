#include <stdio.h>

/*long int cmmdc(long int a,long int b){
	//long int c;
	while(a!=b){
	   if(a>b){
		 a=a%b;
	   }else{
         b-=a;
	   }
	}
	return a;
}*/

long int cmmdc(long int a,long int b){
 long int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
	
    return a;
}

int main(){
   int T;
   long int a,b;
   FILE *fin=fopen("euclid2.in","r");
   FILE *fout=fopen("euclid2.out","w");
   
   fscanf(fin,"%d",&T);
   for(int i=0;i<T;i++){
       fscanf(fin,"%ld %ld",&a,&b);
	   fprintf(fout,"%ld\n",cmmdc(a,b));
   }
	   
return 0;
}
