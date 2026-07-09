#include <fstream>

using namespace std;

int gcd(int a, int b) {
    return b == 0? a : gcd(b, a%b);
}

int main() {
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int n;
    int n1, n2;

    f>> n;
    for (int i = 0; i < n; i++)
    {
        f>> n1>> n2;
        if (n1 > n2) {
            int aux = n1;
            n1 = n2;
            n2 = aux;
        }

        g<< gcd(n1, n2) << "\n";
    }

    return 0;
}