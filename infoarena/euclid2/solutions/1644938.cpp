#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n, x, y, z; f >> n;
    for(; n; n --) {
        f >> x >> y;
        while(y) {
            x = x % y;
            z = x; x = y; y = z;
        }
        g << x << "\n";
    }
    return 0;
}
