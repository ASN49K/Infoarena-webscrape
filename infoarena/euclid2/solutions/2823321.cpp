#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;

int euclid(int a,int b)
{
    int ma = max(a,b),mn = min(a,b);
    if (mn == 0)
        return ma;
    return euclid(mn,ma % mn);
}

int main()
{
    in >> t;
    int a,b;
    for (int i = 1; i <= t; i++)
    {
        in >> a >> b;
        out << euclid(a,b) << '\n';
    }
    return 0;
}
