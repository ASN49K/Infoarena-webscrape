# include <stdio.h>
FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
int main()
{
   long a,b,r;
   fscanf(f,"%ld %ld",&a,&b);
   fclose(f);
   do
   {
    r=a%b;
    a=b;
    b=r;
   }while (r);
   fprintf(g,"%ld",a);
   fclose(g);
  return 0;
}