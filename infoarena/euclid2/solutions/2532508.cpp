#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b) {
    if (!b)
        return a;
    else
        return GCD(b,a%b);
}

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        fin >> x >> y;
        fout << GCD(x,y) << '\n';
    }
    return 0;
}
