#include <cstdio>

using namespace std;
int n;
struct cmmdc
{
    int a,b;
}v;
int Euclid(int a, int b)
{
   while(b)
   {
       int r=a%b;
       a=b;
       b=r;
   }
   return a;
}
void rezolvare(int n)
{
    for(int i=0;i<n;i++)
        {scanf("%d %d",&v.a,&v.b);
        printf("%d\n",Euclid(v.a,v.b));
        }
}
int main()
{

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    rezolvare(n);
    return 0;
}
