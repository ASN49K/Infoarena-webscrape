#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T;

int main()
{
    in >> T;
    int x, y;
    while (T--){
        in >> x >> y;
        int r;
        while (y){
            r = x % y;
            x = y;
            y = r;
        }
        out << x << '\n';
    }

    in.close();
    out.close();
    return 0;
}