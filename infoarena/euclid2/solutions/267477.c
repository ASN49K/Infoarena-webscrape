#include <stdio.h>

int x,y,z;

int imparte(int a,int b)
{

 if(!b) return a;
        else imparte(b,a%b);

}

int main()
{


 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);


 scanf("%d", &x);

 for(, x, --x)
  {
   scanf("%d %d", &y, &z)
   printf("%d\n", imparte(y,z));
  }



 return 0;
}
