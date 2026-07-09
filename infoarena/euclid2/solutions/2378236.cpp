#include <bits/stdc++.h>
using namespace std;

int euclid(int a, int b)
{
    if(a == b)
        return a;
    else if(!(a&1 || b&1))
        return euclid(a>>1, b>>1)<<1;
    else if(!(a&1))
        return euclid(a>>1, b);
    else if(!(b&1))
        return euclid(a, b>>1);
    else
    {
        if(a > b)
            return euclid((a-b)>>1, b);
        else
            return euclid(a, (b-a)>>1);
    }
}

int main()
{
    int x, y, nr_perechi;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &nr_perechi);
    while(cin >> x >> y)
    cout << euclid(x, y) << '\n';
    return 0;
}
