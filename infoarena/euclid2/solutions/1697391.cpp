#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

ll cmmdc(ll a, ll b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;

    while(b != 0)
    {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ifstream in;
    ofstream out;

    in.open("euclid2.in");
    out.open("euclid2.out");

    int t;
    in >> t;
    while(t--) {
        ll a, b;
        in >> a >> b;
        out << cmmdc(a,b) << endl;
    }

    in.close();
    out.close();
    return 0;
}
