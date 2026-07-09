#include <stdio.h>

using namespace std;
//ifstream in("euclid2.in");
//ofstream out("euclid2.out");

int cmmdc(int x, int y)
{
  if (y==0) return x;
  return cmmdc(y,x%y);
}

int main()
{
  freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  int a,b,r,t;
  scanf("%d",&t);
  for (int i=1;i<=t;i++)
  {
    scanf("%d %d",&a,&b);
    printf("%d\n",cmmdc(a,b));
  }
  return 0;
}
