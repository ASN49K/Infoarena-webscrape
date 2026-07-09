#include <stdio.h>

int euclid(int a,int b);


int main() {
	FILE *in,*out;
	int T,i,a,b;

	if((in=fopen("euclid2.in","r"))==NULL) {
										   printf("fisier inaccesibil\n");
										   exit(1);
										   }
    if((out=fopen("euclid2.out","w"))==NULL){
 											 printf("fisier inaccesibil\n");
										   	 exit(1);
										   }
    fscanf(in,"%d",&T);
    for(i=0;i<T;i++) {
    				 fscanf(in,"%d%d",&a,&b);
    				 fprintf(out,"%d\n",euclid(a,b));
					 }
    fclose(in);
    fclose(out);
    return 0;
}

int euclid(int a,int b) {
	int r;
	r=a%b;
	while(r!=0){
				a=b;
				b=r;
				r=a%b;
				}
	return b;
}
    				 
    
