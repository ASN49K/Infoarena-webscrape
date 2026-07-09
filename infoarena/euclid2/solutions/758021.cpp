#include<iostream>
#include<fstream>

using namespace std;

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    int n, a, b;
    in >> n;
    for(int i=0; i<n; i++)
    {
        in >> a;
        in >> b;
        out << gcd(a, b) << endl;
    }
    in.close();
    out.close();
}
