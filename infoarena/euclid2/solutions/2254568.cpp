#include <iostream>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int n, a, b, c;

    scanf("%d", &n);

    for(int i=0; i<n; ++i)
    {
        scanf("%d%d", &a, &b);

        while(b)
        {
            c = a;
            a = b;
            b = c%b;
        }

        printf("%d\n", a);
    }

    return 0;
}
