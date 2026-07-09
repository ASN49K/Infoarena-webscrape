#include <stdio.h>
FILE *f,*g;
int main()
{long int r,a,b;
	      f=fopen("euclid2.in","r");
	      g=fopen("euclid2.out","w");
	      fscanf(f,"%ld");
	      while(!feof(f))
	    {  fscanf(f,"%ld%ld",&a,&b);

      r=a%b;
	      while(r!=0)
		   {a=b;
		    b=r;
		    r=a%b;
		   }
	      fprintf(g,"%ld \n",b);
	    }
 fclose(f);
 fclose(g);
 return 0;
}