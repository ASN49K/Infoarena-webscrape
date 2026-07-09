#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout("euclid2.out");

    int T;

    fin >> T;

    for (int i = 0; i < T; ++i) {
        int a, b;
        fin >> a >> b;

        while (b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }

        fout << a;
    }

    fin.close();
    fout.close();

    return 0;
}
