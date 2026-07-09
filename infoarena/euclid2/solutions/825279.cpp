#include <iostream>
#include <stdio.h>

using namespace std;


FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

int a,b,n,i;

int euclid(int a,int b)
{
  if (b==0){

   return a;
   }
       else euclid(b,a%b);
}




int main()
{
      fscanf(f,"%d%d",&n);

     for (i=1;i<=n;i++){
       fscanf(f,"%d%d",&a,&b);
      fprintf(g,"%d",euclid(a,b));
     }

     fclose;
	return 0;
}
