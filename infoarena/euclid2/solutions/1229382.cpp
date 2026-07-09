#include <cstdio>

using namespace std;

int main()
{
    int n,a,b,r;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%d %d",&a,&b);
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        printf("%d\n",a);
        n--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
