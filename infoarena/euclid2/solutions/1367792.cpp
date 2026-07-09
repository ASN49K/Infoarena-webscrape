
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b;

int cmmdc(int a, int b)
{
    while (a!=b)
    {
        if (a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

int main()
{
    f>>n;
    for (int i=1; i<=n; ++i)
    {
        f>>a>>b;
        g<<__gcd(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
