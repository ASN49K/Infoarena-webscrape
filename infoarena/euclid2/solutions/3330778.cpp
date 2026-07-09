#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n;
    fin >> n;
    
    while(n) {
        --n;

        int a, b, c;
        fin >> a >> b;

        while (b) {
            c = b % a;
            a = b;
            b = c;
        }
        fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}