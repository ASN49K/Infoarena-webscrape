#include <fstream>

using namespace std;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");

    int T;

    fin >> T;

    for(int t = 1; t <= T; ++t)
    {
        int N, X, S = 0;

        fin >> N;

        for(int i = 1; i <= N; ++i)
        {
            fin >> X;
            S = S ^ X;
        }

        if(S == 0)
            fout << "NU\n";
        else
            fout << "DA\n";
    }
}
