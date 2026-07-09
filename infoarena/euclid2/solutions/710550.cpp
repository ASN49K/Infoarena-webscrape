#include <cstdio>
#include <cassert>

using namespace std;

int gcd (int A, int B)
{
    int rest;

    while (B)
    {
        rest = A % B;
        A = B;
        B = rest;
    }

    return A;
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

