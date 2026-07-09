#include <cstdio>
#include <cstdlib>
using namespace std;




int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int n,t,x;
    scanf("%i", &t);
    for(;t;t--)
    {
               scanf("%i", &n);
               int xorsum=0;
               for(int i=0;i<n;i++)
               {
                               scanf("%i", &x);
                               xorsum=xorsum^x;
               }
               if(xorsum) printf("DA\n");
               else printf("NU\n");
    }
    return 0;
} 
