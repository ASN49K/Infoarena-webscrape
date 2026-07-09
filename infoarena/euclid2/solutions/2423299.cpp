#include <fstream>

std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");

int main()
{
        int t, a, b, rest;
        f >> t;
        while (t--) {
                f >> a >> b;
                while (b) {
                        rest = a % b;
                        a = b;
                        b = rest;
                }
                g << a << '\n';
        }
        return 0;
}
