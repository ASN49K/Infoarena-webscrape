#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in",std::ifstream::in);
    ofstream fout("euclid2.out",std::ofstream::out);
    int n,a,b,r;
    fin >> n;
    for (int i = 0;i < n;i++) {
        fin >> a >> b;
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
