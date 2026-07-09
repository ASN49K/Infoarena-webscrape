#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

int main()
{
    ifstream in;
    ofstream out;

    in.open("euclid2.in");
    cin.sync_with_stdio(true);
    out.open("euclid2.out");
    cout.sync_with_stdio(true);

    int t;
    in >> t;
    while(t--) {
        ll a, b;
        in >> a >> b;
        ll r;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }

        out << a << endl;
    }

    in.close();
    out.close();
    return 0;
}
