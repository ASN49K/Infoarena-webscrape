#include <iostream>
#include <fstream>

using namespace std;
long long heap_size[10001];

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");

    int test;
    fin >> test;
    for (int i = 1; i <= test; ++i) {
        int heaps, nimSum = 0;
        fin >> heaps;
        for (int j = 1; j <= heaps; ++j) {
            fin >> heap_size[j];
            nimSum = nimSum ^ heap_size[j];
        }
        if (nimSum == 0) {
            fout << "NU" << "\n";
        } else {
            fout << "DA" << "\n";
        }
    }

    return 0;
}
