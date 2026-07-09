#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int teste;
    scanf("%d", &teste);

    for(int i = 1; i <= teste; ++i)
    {
        int n;
        scanf("%d", &n);

        int val;

        scanf("%d", &val);

        for(int j = 2; j <= n; ++j)
        {
            int aux;
            scanf("%d", &aux);
            val ^= aux;
        }

        printf("%s\n", val > 0 ? "DA" : "NU");
    }

    return 0;
}
