#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a%b);
}
int t, a, b;

int main()
{
    fin >> t;
    for (; t; --t){
        fin >> a >> b;
        fout << gcd (a, b) << endl;
    }

    return 0;
}
