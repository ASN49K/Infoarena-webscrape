// Iterative solution
// Runtime: O(min(a, b))
// Space-complexity: O(1)

#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    int Min = a < b ? a : b;
    for(int i=Min; i>=2; i--) {
        if(a%i==0 && b%i==0) {
            return i;
        }
    }
    return 1;
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
