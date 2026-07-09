#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main() {
    
    int n;
    fin >> n;
    
    long long a, b;
    for (int i = 1; i <= n; i++) {
        fin >> a >> b;
        while (b != 0) {
            long long r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    
    return 0;
}