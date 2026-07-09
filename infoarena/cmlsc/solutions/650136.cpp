#include<cstdio>
using namespace std;
int i,T,a,b;
void euclid(int a,int b)
{
    int r;
    while (b!=0)
         {
             r=b;
             b=a%b;
             a=r;
         }
    printf("%d\n",a);
}
int main()
    {
        freopen("euclid2.in","r",stdin);
        freopen("euclid2.out","w",stdout);
        scanf("%d",&T);
        for (i=1 ;i<=T;i++)
        {
             scanf("%d%d",&a,&b);
             euclid(a,b);
        }
    }
