#include <iostream>
#include <cstdio>

using namespace std;

int cmmdc(int a,int b)
{
  if (b==0) return a;
  return cmmdc(b,a%b);
}



int main()
{
   freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);


   int a,b,t,i;

   scanf("%d", &t);

   for(i=1;i<=t;i++)
   {
      scanf("%d %d", &a, &b);
      printf("%d\n", cmmdc(a,b));

   }
}
