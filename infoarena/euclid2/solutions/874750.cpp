#include <fstream>

using namespace std;
/*ifstream in ("euclid2.in");
ofstream out ("euclid2.out");*/
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,a,b,i,r;
    scanf("%d",&t);
    i=1;
    while(i<=t)
    {
        scanf("%d%d",&a,&b);
        while(b)
        {
        r=a%b;
        a=b;
        b=r;

        }
        i++;
        printf("%d\n",a);
    }
    return 0;
}
