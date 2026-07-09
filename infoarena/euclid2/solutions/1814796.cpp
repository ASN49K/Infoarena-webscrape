#include <cstdio>

FILE *f=fopen("euclid2.in", "r");
FILE *g=fopen("euclid2.out","w");
int main()
{

     int i,t,a,b,r;
     fscanf(f,"%d",&t);
     for(i=1;i<=t;i++)
     {
         fscanf(f,"%d %d",&a, &b);
         r=a%b;
         while(r)
         {
             a=b;
             b=r;
             r=a%b;

         }
         fprintf(g,"%d %c",b, '\n');
     }
     return 0;

}
