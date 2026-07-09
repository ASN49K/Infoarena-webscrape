#include <stdio.h>

#define INPUT  "euclid2.in"
#define OUTPUT "euclid2.out"

int a,b;

int main()
{
 freopen(INPUT,"r",stdin);
 freopen(OUTPUT,"w",stdout);

 scanf("%d%d",&a,&b);
 while (a!=b)
      if (a>b) a-=b;
        else b-=a;

 printf("%d\n",a);

 fclose(stdin);
 fclose(stdout);
 return 0;
}
