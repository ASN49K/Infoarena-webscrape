#include <fstream>

using namespace std;

FILE* f=freopen("euclid2.in","r",stdin);
FILE* o=freopen("euclid2.out","w",stdout);

int n;

int Euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",Euclid(a,b));
    }

    return 0;
}
