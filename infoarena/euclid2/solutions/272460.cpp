#include<stdio.h>
int main ()
{
 FILE *f,*g;
unsigned long t,a,b,r,i;
//fstream f("euclid2.in",ios::in);
//fstream g("euclid2.out",ios::out);
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%ld",&t);
//f>>t;
for(i=1;i<=t;i++)
 {
 //f>>a>>b;
 fscanf(f,"%ld%ld",&a,&b);
  do
   {
   r=a%b;
   a=b;
   b=r;
   }
  while(r);
 //g<<a<<'\n';
 fprintf(g,"%ld\n",a);
 }
 fclose(f);
 fclose(g);
return 0;
}
