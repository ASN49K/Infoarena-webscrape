#include<stdio.h>

int main()
{
FILE *f, *g;
f = fopen("euclid2.in","r");
g = fopen("euclid2.out","w");

int t,a ,b,i, c, reminder;
fscanf(f,"%d ",&t);
for(i=0;i<t;i++){
	fscanf(f,"%d %d ",&a,&b);	
	do{	
		if(a<b){
			reminder = a; a = b; b= reminder;
		}
		reminder = a % b;
		if(reminder != 0){
			a = b;
			b = reminder;
		} 
	}while(reminder != 0 );
	fprintf(g,"%d\n",b);
}


return 0;
}
