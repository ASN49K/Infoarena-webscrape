// Euclid's Algorithm (iterative / recursive) solution
// Runtime: O(log(max(a, b)))
// Space-Complexity: O(1)

#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd_iterative(int a, int b) {
    while(b) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int gcd(int a, int b) {
    if(!b) {
        return a;
    }
    return gcd(b, a%b);
}

int main()
{
    int T, a, b;
    fin >> T;
    while(T--) {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
