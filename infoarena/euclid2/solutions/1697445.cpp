#include <iostream>
#include <fstream>

using namespace std;

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
        int a, b;
        in >> a >> b;
        int r;
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
