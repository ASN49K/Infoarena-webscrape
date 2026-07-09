#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;
int t,n,x,y;
int main()
{

   freopen("nim.in","r",stdin);
   freopen("nim.out","w",stdout);
   scanf("%d",&t);
   for(;t;t--)
   {
       scanf("%d",&n);
       for(x=0;n;n--)
       {
           scanf("%d",&y);
           x^=y;
       }
       x?printf("DA\n"):printf("NU\n");
   }
    return 0;
}
