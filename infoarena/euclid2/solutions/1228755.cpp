#include <cstdio>

using namespace std;

int t,a,b;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);

    while (t>0)
    {
        scanf("%d %d",&a,&b);
        while (b!=0)
        {
            int t=b;
            b=a%b;
            a=t;
        }
        printf("%d\n",a);
        --t;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
