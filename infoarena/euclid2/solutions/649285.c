#include <stdio.h>

int cmmdc(int a, int b)
{if (b==0)
  return a;
 return cmmdc(b,a%b);
}

int main()
{int a,b,n,i;
FILE *f,*g;	
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
i=0;
fscanf(f,"%i",&n);
while (i<n)
	{i++;
	fscanf(f,"%i%i",&a,&b);
	fprintf(g,"%i\n",cmmdc(a,b));
	}
fclose(f);
fclose(g);
return 0;
}
		
