#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int S, x, T, N;

int main()
{
    fin >> T;

    while(T--) {
        fin >> N; S = 0;

        for(int i = 1; i <= N; i++)
            fin >> x, S ^= x;

        fout << ((S) ? "DA" : "NU") << '\n';
    }
    fin.close();
    fout.close();

    return 0;
}
