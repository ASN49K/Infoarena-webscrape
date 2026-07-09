#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    do
    {
        int r = a%b;
        a = b;
        b = r;
    }while(b);
    return a;
}


int main()
{
    int n,x,y;
    in >> n;
    for (int i = 1; i<=n; i++)
    {
        in >> x >> y;
        out << cmmdc(x,y) << "\n";
    }
}
