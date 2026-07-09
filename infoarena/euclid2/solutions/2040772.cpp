#include <cstdio>

using namespace std;

int x,y,n;

int cmmdc(int x,int y)
{
    if(y==0)
        return x;
    return cmmdc(y,x%y);
}

int main()
{

   freopen("euclid2.in","r",stdin);
   freopen("euclid2.out","w",stdout);

   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       scanf("%d %d",&x,&y);
       printf("%d\n",cmmdc(x,y));
   }
    return 0;
}
