#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

/*int cmmdc (int a, int b) {
    if (!b) return a;
    else return cmmdc(b, a % b);
}*/
int main()
{
    int n;
    f >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        f >> x >> y;
        //g << cmmdc(x, y) << "\n";
        int r;
        r = x % y;
        while (r != 0) {
            x = y;
            y = r;
            r = x % y;
        }
        g << y << "\n";
    }
    return 0;
}
