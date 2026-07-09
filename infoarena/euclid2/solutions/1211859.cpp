#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{   int n, a, b;
    f>>n;
    while (n--) {
    f>>a>>b;
    while (b) {
        int r;
        r=a%b;
        a=b;
        b=r; }
    g<< a << "\n"; }
    return 0;
}
