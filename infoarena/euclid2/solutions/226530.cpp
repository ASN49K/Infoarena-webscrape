#include<stdio.h>
#include<math.h>
int nr;
int n;
int i;
int n1,n2;

int cmmdc(int a, int b)
{
    int r;
    while (a%b != 0)
      {
          r = a % b;
          a = b;
          b = r;
      }
    return b;
}

int main()
{
     freopen("euclid2.in","r",stdin);
     freopen("euclid2.out","w",stdout);
     scanf("%d",&n);
     for(i = 1; i <= n; i++)
      {
       scanf("%d %d",&n1,&n2);
       printf("%d \n",cmmdc(n1,n2));
      }
    return 0;
}
