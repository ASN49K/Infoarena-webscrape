#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int numberPairs, a, b;

int resultFor(int a, int b) {
    if (a % b)
        return resultFor(b, a % b);
    else
        return b;
}

int main()
{
    fin >> numberPairs;
    for (int i = 1; i <= numberPairs; ++i) {
        fin >> a >> b;
        if (a > b)
            fout << resultFor(a, b) << "\n";
        else
            fout << resultFor(b, a) << "\n";
    }
    return 0;
}
