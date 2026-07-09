#include <iostream>
#include <fstream>
using namespace std;

ifstream f ("nim.in");
ofstream g ("nim.out");

int main()
{
    int T, N, x, s;
    f >> T;
    while(T--) {
        f >> N;
        s = 0;
        while(N--) {
            f >> x;
            s ^= x;
        }
        g << (s != 0) ? "DA\n" : "NU\n";
    }
    f.close();
    g.close();
    return 0;
}
