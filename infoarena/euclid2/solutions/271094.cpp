#include <stdio.h>
FILE *f,*g;
int main()
{long int r,a,b;
 unsigned int n,i;
	      f=fopen("euclid2.in","r");
	      
	      fscanf(f,"%ld",&n);
	      g=fopen("euclid2.out","w");
	      for (i=1;i<=n;i++)
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