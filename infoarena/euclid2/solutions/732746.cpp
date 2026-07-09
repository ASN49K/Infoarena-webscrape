#include <stdio.h>

int cmmdc(int a,int b){
	int r;
	r=a % b;
	while (r!=0) {
		a=b;
		b=r;
		r=a % b;
		
	}
	
	if (b==0) b=1;
	return b;
}


main(){
FILE *f,*g;
int a,b,i,n;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%d",&n);
for(i=1;i<=n;i++)
 {
	 fscanf(f,"%d",&a);
	 fscanf(f,"%d",&b);
	 fprintf(g,"%d\n",cmmdc(a,b));
     
 }
fclose(g);

return 0;

}
