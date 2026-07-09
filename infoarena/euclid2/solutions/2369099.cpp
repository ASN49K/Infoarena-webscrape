#include <fstream>
using namespace std;
int t, a, b, r;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> t;
    for (int i=1;i<=t;i++) {
        fin >> a >> b;
        while (b>0) {
            r = a%b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }
    return 0;
}
