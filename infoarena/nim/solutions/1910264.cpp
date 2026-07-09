#include <cstdio>

using namespace std;

int n, m;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &n);

    for(int k = 0; k < n; k++)
    {
        scanf("%d", &m);

        int sum = 0;

        for(int i = 0; i < m; i++)
        {
            int tmp;
            scanf("%d", &tmp);

            sum ^= tmp;
        }

        if(sum == 0)
        {
            printf("NU\n");
        }
        else
        {
            printf("DA\n");
        }
    }

    return 0;
}
