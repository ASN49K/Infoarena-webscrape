#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int n, a, b;
int main()
{
    in >> n;
    for(int i = 1;i <= n;i++)
    {
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }
    return 0;
}
