#include <iostream>

using namespace std;

int main()
{
      freopen("euclid2.in","r",stdin);
      freopen("euclid2.out","w",stdout);
            
      int t,a,b,r,i;
      
      scanf("%d",&t);
      
      for(i=1;i<=t;i++)
      {
            scanf("%d %d",&a,&b);
            while(a)
            {
                    r=b%a;
                    b=a;
                    a=r;
            }
            printf("%d \n",b);
      }
      return 0;
}
      
