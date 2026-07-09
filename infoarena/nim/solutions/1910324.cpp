#include <iostream>
#include <cstdio>

using namespace std;

int n, m, tmp, s;

void citire()
{
    scanf("%d\n",&n);

    for(int i = 0 ; i < n ; ++i)
    {
        s = 0;

        scanf("%d\n",&m);

        for(int j = 0 ; j < m ; ++j)
        {
            scanf("%d\n",&tmp);

            s ^= tmp;
        }

        if(s)
        {
            printf("DA\n");
        }
        else
        {
            printf("NU\n");
        }
    }
}

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    citire();

    return 0;
}
