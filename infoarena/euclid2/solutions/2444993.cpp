#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    int r = a % b;

    while(r) {

        a = b;
        b = r;
        r = a % b;

    }

    return b;
}

int main()
{
    int T; fin >> T;

    for(int i = 1; i <= T; i++) {

        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << '\n';

    }

    return 0;
}
