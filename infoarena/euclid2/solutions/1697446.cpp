#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    ofstream out;

    in.open("euclid2.in");
    out.open("euclid2.out");

    int t;
    in >> t;
    for(;t;--t) {
        int a,b;
        in >> a >> b;
        while(b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        out << a << "\n";
    }

    in.close();
    out.close();
    return 0;
}
