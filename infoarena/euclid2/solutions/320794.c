#include <stdio.h>
#include <stdlib.h>    

unsigned long cmmdc (unsigned long a,unsigned long b)
{
if (b==0) return a;
return cmmdc(b,a%b); 
}

int main()     
{     
FILE *in,*out;  
unsigned long x,y,t;
in=fopen("euclid2.in","r");     
out=fopen("euclid2.out","w");     
fscanf(in,"%lu",&t); 

while(t)
{
fscanf(in,"%lu %lu",&x,&y);
fprintf(out,"%lu\n",cmmdc(x,y));
t--;
}       
fclose(in);
fclose(out);     
return 0;
}

     



