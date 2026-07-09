# include <stdio.h>
FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
long T,i,a,b;
long euclid(long a, long b)
{
  long r;
   do
   {
    r=a%b;
    a=b;
    b=r;
   }while (r);
   return a;
}
int main()
{
   fscanf(f,"%ld",&T);
   for (i=1;i<=T;i++)
   {
	fscanf(f,"%ld %ld",&a,&b);
	fprintf(g,"%ld\n",euclid(a,b));
   }
   fclose(g);
   fclose(f);
  return 0;
}