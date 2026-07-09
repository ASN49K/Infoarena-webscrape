#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n, a, b, r;
int main()
{
    f >> n;
    for(int i = 1; i <= n; i++) {
        f >> a >> b;
        while(b) {
            r = a%b;
            a = b;
            b = r;
        }
        g << a << endl;
    }
    return 0;
}
