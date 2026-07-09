#include<cstdio>
using namespace std;

int N, T, X;
int sol, i;

int main()
    {
        freopen("nim.in","r",stdin);
        freopen("nim.out","w",stdout);

        for (scanf("%d", &T); T; T--)
        {
            scanf("%d", &N); sol = 0;
            for (i = 1; i <= N; i++)
            {
                scanf("%d", &X);
                sol = sol ^ X;
            }

            if (sol)
                printf("DA\n");
            else
                printf("NU\n");
        }
    }
