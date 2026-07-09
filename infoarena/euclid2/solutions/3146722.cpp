#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
    int n, a, b, rest;
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> a >> b;
        while (b != 0) {
            rest = a % b;
            a = b;
            b = rest;
        }

        g << a << endl;
    }
    
}
