#include <cstdio>
#include <cassert>

using namespace std;

int gcd (int A, int B)
{
    int d;

    for (d = A > B ? A : B; d >= 1; d --)
        if (A % d == 0 && B % d == 0)
            return d;
}

int main ()
{
    int A, B, testCases;

    assert (freopen ("euclid2.in", "r", stdin) != NULL);
    assert (freopen ("euclid2.out", "w", stdout) != NULL);

    assert (scanf ("%d", &testCases) != EOF);
    while (testCases)
    {
        assert (scanf ("%d %d", &A, &B) != EOF);
        printf ("%d\n", gcd (A, B));
        testCases --;
    }

    return 0;
}

