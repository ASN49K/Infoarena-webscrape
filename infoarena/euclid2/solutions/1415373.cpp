#include <cstdio>
using namespace std;
int T,i,a[100],b[100],r;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
        scanf("%d %d",&a[i],&b[i]);
    //for(i=1;i<=T;i++)
     //   printf("%d %d\n",a[i],b[i]);
    for(i=1;i<=T;i++)
    {
        if(a[i]>b[i])
        {
            while(a[i]%b[i]!=0)
            {
                r=a[i]%b[i];
                a[i]=b[i];
                b[i]=r;
            }
            printf("%d\n",b[i]);
        }
        else
        {
            while(b[i]%a[i]!=0)
            {
                r=b[i]%a[i];
                b[i]=a[i];
                a[i]=r;
            }
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
