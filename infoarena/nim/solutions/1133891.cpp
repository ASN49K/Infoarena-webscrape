#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

    int T, N, XOR, nr, i, j;

	scanf("%d", &T);

	for (i = 0; i < T; ++i)
    {
        scanf("%d", &N);
        XOR = 0;
        for (j = 0; j < N; ++j)
        {
            scanf("%d", &nr);
            XOR ^= nr;
        }
        if (XOR) printf("DA\n");
        else printf("NU\n");
    }

	fclose(stdout);
    return 0;
}
