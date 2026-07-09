#include <fstream>

std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");

int cmmdc(int A, int B) {
        short rest;
        while (B) {
                rest = A % B;
                A = B;
                B = rest;
        }
        return A;
}

int main()
{
        int t, a, b;
        f >> t;
        while (t--) {
                f >> a >> b;
                g << cmmdc(a, b);
        }
        return 0;
}
