#include <stdio.h>
#include <stdlib.h>

int main()
{

  FILE *citire,*scriere;
citire = fopen("euclid2.in", "r");
scriere = fopen("euclid2.out","w");
int a,b,n;
     fscanf(citire,"%d",&n);

for(;n>0;n--)
   {fscanf(citire,"%d",&a);
    fscanf(citire,"%d",&b);

if(a>0&&b>0)
    while(a>1&&b>1)
      if(a>b)
        a=a%b;
      else if(b>a)
        b=b%a;
  if(a==1||b==1)
        fprintf(scriere,"%d\n",1);
  else
fprintf(scriere,"%d\n",b);
   }




    return 0;
}
