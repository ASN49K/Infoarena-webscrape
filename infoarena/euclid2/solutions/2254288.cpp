#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b) {
    if(!b) {
        return a;
    }
    return cmmdc(b, a % b);
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
