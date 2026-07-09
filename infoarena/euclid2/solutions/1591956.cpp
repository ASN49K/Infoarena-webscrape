#include <fstream>

using namespace std;

ofstream out("euclid2.out");

int cmmdc(int a,int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int n,m,i,k;

int main()
{
    freopen("euclid2.in","r",stdin);
    scanf("%d",&k);
    for(i = 1 ; i <= k ; i++)
    {
        scanf("%d%d",&n,&m);
        out<<cmmdc(n,m)<<'\n';
    }

    return 0;
}
