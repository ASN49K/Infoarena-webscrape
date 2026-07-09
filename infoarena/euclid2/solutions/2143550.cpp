#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t, a, b;
    in >> t;
    while(t--)
    {
        in >> a >> b;
        out << gcd(a, b) << "\n";
    }
    in.close();
    out.close();
    return 0;
}
