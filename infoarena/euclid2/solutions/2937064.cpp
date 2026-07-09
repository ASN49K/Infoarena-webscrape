#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream intrare("euclid2.in");
    ofstream iesire("euclid2.out");

    unsigned int perechi, a, b, m, r;
    bool found = false;
    intrare >> perechi;

    while (perechi != 0) {
        intrare >> a >> b;
        m = min(a, b);

        r = 1;
        for (int i = 2; i <= m; i++) {
            if ((a % i == 0) && (b % i == 0)) {
                r = i;
            }
        }

        iesire << r << endl;
        perechi--;
    }

    return 0;
}
