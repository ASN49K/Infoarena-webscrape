#include <stdio.h>

using namespace std;

int algoritmEuclid(int a, int b)
{

    return (!b)?a:algoritmEuclid(b, a%b);

}

int main()
{
    freopen("euclid2.in",  "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t, a, b;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &a, &b);
        printf("%d \n", algoritmEuclid(a, b));
    }

    return 0;
}
