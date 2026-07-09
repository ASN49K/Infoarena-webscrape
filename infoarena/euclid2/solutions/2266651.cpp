#include <fstream>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int a,b;
    fin>>a>>b;
    fout<<gcd(a,b);
    return 0;
}
