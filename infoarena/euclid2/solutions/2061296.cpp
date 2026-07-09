#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in",std::ifstream::in);
    ofstream fout("euclid2.out",std::ofstream::out);
    int n,a,b,tmp;
    fin >> n;
    for (int i = 0;i < n;i++) {
        fin >> a >> b;
        //alg
        while (b) {
            if (a < b) {
                a ^= b;
                b ^= a;
                a ^= b;
            }
            a = a - b;
        }
        fout << a << endl;
    }

    return 0;
}

