#include<stdio.h>
int main()
{int n,a,b,t;
 FILE *f,*g;
 f=fopen("euclid2.in","r");
 g=fopen("euclid2.out","w");
 fscanf(f,"%d",&n);
 while(n)
  {fscanf(f,"%d %d",&a,&b);
   while(b)
    {t=b;
     
     b=a%b;
     a=t;
    }
   fprintf(g,"%d\n",a);
   n--;
  }
 fclose(f);
 fclose(g);
 return 0;
}
