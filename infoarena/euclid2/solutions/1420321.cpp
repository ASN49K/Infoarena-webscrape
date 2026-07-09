#include <iostream>
#include <cstdio>

using namespace std;

int cmmdc(int a, int b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return cmmdc(b, a%b);
    }
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int nr;

    scanf("%i", &nr);

    for(int i = 0; i < nr; i++)
    {
        int nr1, nr2;

        scanf("\n%i %i", &nr1, &nr2);

        printf("%i\n", cmmdc(nr1, nr2));
    }

    return 0;
}
