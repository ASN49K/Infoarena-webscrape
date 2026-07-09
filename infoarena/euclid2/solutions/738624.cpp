#include <iostream>
#include <cstdio>
using namespace std;

long cmmdc(long a, long b)
{
    if(b == 0)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    FILE *f = fopen("euclid2.in", "r");
//    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    long a, b;
    int n;
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        fscanf(f, "%ld%ld", &a, &b);
        cout << cmmdc(a, b) << '\n';
    }

    return 0;
}
