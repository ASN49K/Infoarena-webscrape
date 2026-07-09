#include<stdio.h>
int main()
{long a,b,i,t,j;

FILE *f=fopen("euclid.in","r");
FILE *g=fopen("euclid.out","w");


fscanf(f,"%ld",&t);

for(j=1;j<=t;j++)
{
 fscanf(f,"%ld %ld",&a,&b);

 if(b%a==0) fprintf(g,"%ld",a);
 else{ if(1%b==0) fprintf(g,"%ld",b);
      else {if(a>b) {for(i=b;i>=2;i++)
   	            if((a%i==0)&&(b%i==0))
		   { fprintf(g,"%ld\n",i);
     	             break;}
                    }
            else {for(i=a;i>=2;i++)
                  if((a%i==0)&&(b%i==0))
	            { fprintf(g,"%ld\n",i);
	              break;}
		}}}
 }

fclose(f);
fclose(g);
return 0;
}