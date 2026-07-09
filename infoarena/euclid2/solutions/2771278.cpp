// Repetitive substractions solution
// Runtime: O(a+b)
// Space-complexity: O(1)

#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    if(!b) {
        return a;
    }
    if(a > b) {
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
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
