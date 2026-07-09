#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int N;
long long xorSum;

int main()
{
    int T;
    fin >> T;

    for(int i = 1; i <= T; i++)
    {
        fin >> N;
        xorSum = 0;

        for(int j = 1; j <= N; j++)
        {
            long long x;
            fin >> x;
            xorSum ^= x;
        }

        if(xorSum > 0)
            fout << "DA\n";
        else
            fout << "NU\n";
    }

    return 0;
}
