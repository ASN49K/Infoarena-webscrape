#include <bits/stdc++.h>
#include <cassert>

using namespace std;

fstream f ("euclid2.in", ios::in);
fstream g ("euclid2.out", ios::out);

uint64_t gcd(uint64_t a, uint64_t b)
{ return (b == 0) ? a : gcd(b, a % b); }

int main()
{
    uint16_t n; tuple<uint64_t, uint64_t> pr;
    assert(f >> n);
    for(uint16_t i = 0; i < n; i++)
    {
        assert(f >> get<0>(pr) >> get<1>(pr));
        assert(g << gcd(get<0>(pr), get<1>(pr)) << "\n");
    }
    return 0;
}
