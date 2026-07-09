#include <bits/stdc++.h>
using namespace std;
fstream in("euclid2.in");
ofstream out("euclid2.out");

int T;

int Rezolv(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int a, b;
    in >> T;
    while(T--)
    {
        in >> a >> b;
        out << Rezolv(a, b) << "\n";
    }
    return 0;
}
