#include <bits/stdc++.h>
#define infile "nim.in"
#define outfile "nim.out"

using namespace std;
int t, n, x, sum;
int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            sum ^= x;
        }
        if (sum) printf("DA\n");
        else printf("NU\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
