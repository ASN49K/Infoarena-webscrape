#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int teste,n;
    scanf("%d", &teste);

    while(teste--)
    {
        scanf("%d", &n);
        int sum = 0, nr;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &nr);
            sum ^= nr;
        }
        printf("%s\n", sum ? "DA" : "NU");
    }



    return 0;
}
