#include <stdio>

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("C:\Users\Iulia\<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="3e7d52514b5a7e735f5752106c4b">[email protected]</a>\sursa\Codeblocks\euclid2.in", "r", stdin);
    freopen("C:\Users\Iulia\<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="692a05061c0d2924080005473b1c">[email protected]</a>\sursa\Codeblocks\euclid2.out", "w", stdout);

    //for (scanf("%d", &T); T; --T)
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }

    return 0;
}
