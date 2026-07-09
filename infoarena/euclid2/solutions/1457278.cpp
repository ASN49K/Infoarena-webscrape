#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int N;

int main()
{
    fin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int a, b;
        fin >> a >> b;
        while (b > 0)
        {
            int c = a % b;
            a = b;
            b = c;
        }

        fout << a << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
