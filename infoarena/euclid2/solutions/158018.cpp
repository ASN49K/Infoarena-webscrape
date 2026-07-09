#include<stdio.h>

FILE *f1,*f2;
int main()
{long unsigned a,b,cmmdc,t,n,i;
f1=fopen("cmmdc.in","r");
f2=fopen("cmmdc.out","w");
fscanf(f1,"%lu",&n);
for(i=0;i<n;i++)
{fscanf(f1,"%lu %lu",&a,&b);
if(a<b)
cmmdc=a;
else
cmmdc=b;
while((a%cmmdc!=0)||(b%cmmdc!=0))
{cmmdc--;}
fprintf(f2,"%lu\n",cmmdc); }











fclose(f1);
fclose(f2);
return 0;}