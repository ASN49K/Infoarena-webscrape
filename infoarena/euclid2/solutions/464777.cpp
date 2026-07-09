#include <stdio.h>
using namespace std;

int main(void)
{int t,a,b,r;
 FILE *fin=fopen("euclid2.in","r");
 FILE *fout=fopen("euclid2.out","w");
 
 fscanf(fin,"%d",&t);
 for(;t>0;t--)
	 {fscanf(fin,"%d %d",&a,&b);
	  do
		 {r=a%b; a=b; b=r;
		 }while (b!=0);
	  fprintf(fout,"%d\n",a);
	 }
 fclose(fin); fclose(fout);
 return 0;
}
