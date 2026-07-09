#include <fstream>
#include <vector>
using namespace std;
ofstream fout("nim.out");
ifstream fin("nim.in");

int T, n;

int main()
{
    fin >> T;

    for(int i=1, rez; i<=T; i++)
    {
        fin >> n;
        for(int i=1, x; i<=n; i++) {
            fin >> x;
            if(i >= 2) rez ^= x;
            else rez = x;
        }

        if(rez) fout << "DA\n";
        else fout << "NU\n";
    }

    return 0;
}
