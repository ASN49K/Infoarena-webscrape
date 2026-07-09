#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b) {
    int t;
    while(b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int a, b, n;

    fin >> n;

    for(int i=1; i<=n; i++) {
        fin >> a >> b;
        fout << cmmdc(a, b) << endl;
    }

    return 0;
}
