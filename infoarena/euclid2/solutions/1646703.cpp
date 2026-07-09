#include <cstdio>
using namespace std;

int euclid(int a,int b)
{
    if(a==0) return b;
    return euclid(b%a,a);
}

int main()
{
    int n,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(;n;n--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
