#include <iostream>
#include <cstdio>

using namespace std;

int euclid(int a, int b)
{
    if(!b)
    {
        return a;
    }

    return euclid(b,a%b);
}

void citire()
{
    int tmp;

    scanf("%d\n",&tmp);

    int a, b;

    for(int i = 0 ; i < tmp ; ++i)
    {
        scanf("%d %d\n",&a,&b);

        printf("%d\n",euclid(a,b));
    }
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    citire();

    return 0;
}
