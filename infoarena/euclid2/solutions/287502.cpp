#include<stdio.h>
long i,t,x,y,r;
long min(long a,long b)
{ if(a<b) return a; return b; }
FILE *f,*g;
int main()
{ f=fopen("euclid2.in","r"); g=fopen("euclid2.out","w");
  fscanf(f,"%ld",&t);
  for(i=1;i<=t;i++)
   { fscanf(f,"%ld%ld",&x,&y);
     r=x%y;
     if(r==0) fprintf(g,"%ld\n",min(x,y));
     else
      { while(r!=0)
	 { x=y;
           y=r;
	   r=x%y;
	 }
	fprintf(g,"%ld\n",y);
      }
   }
  fclose(g);
  return 0;
}