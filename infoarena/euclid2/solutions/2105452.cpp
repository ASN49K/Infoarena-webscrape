#include <cstdio>

using namespace std;

int euclid(int a , int b)
{
    int rest;
    while(b)
    {
        rest = a%b;
        a = b;
        b = rest;
    }
    return a;
}

void read()
{
    int n,a,b,cmmdc;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0 ; i < n ;  i++)
    {
        scanf("%d %d",&a,&b);
        cmmdc = euclid(a,b);
        printf("%d\n",cmmdc);
    }
}


int main()
{
    read();
    return 0;
}
