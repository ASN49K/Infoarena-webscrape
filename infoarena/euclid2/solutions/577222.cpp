#include <cstdio>

using namespace std;

FILE *fin=freopen("euclid2.in","r",stdin);
FILE *fout=freopen("euclid2.out","w",stdout);

int t;

int cmmdc(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
    return 0;
}
