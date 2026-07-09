#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

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

    return 0;
}
