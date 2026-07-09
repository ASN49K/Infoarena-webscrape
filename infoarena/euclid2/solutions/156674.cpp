#include<stdio.h>
int t,a,b;

int euclid(int a,int b)
{
  if (a<b) { a=a-b; b=a+b; a=b-a; };
  while (a%b!=0 && b!=1)
  {
    a=a%b;
    a=a-b;
    b=a+b;
    a=b-a;
  }
  return b;
}

void citire()
{
  freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  scanf("%d",&t);
  for (int i=0;i<t;i++)
  {
    scanf("%d%d",&a,&b);
    printf("%d\n",euclid(a,b));
  }
  fclose(stdin);
  fclose(stdout);
}

int main()
{
  citire();
  return 0;
}