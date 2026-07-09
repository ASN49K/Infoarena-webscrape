#include <cstdio>

using namespace std;

FILE *fin=freopen("euclid2.in","r",stdin);
FILE *fout=freopen("euclid2.out","w",stdout);

int t,a,b;

int cmmdc(int x, int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;y=r;
    }
    return x;
}

int main()
{
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d %d\n",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
