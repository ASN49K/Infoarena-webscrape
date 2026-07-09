#include <fstream>
using namespace std;

int t, a, b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f>>t;
    for (; t; --t) {
        f>>a>>b;
        int c;
        while (b) {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<'\n';
    }
    return 0;
}
