#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GetGCD(int a, int b)
{
    int r = a % b;

    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main()
{
    int tests, A, B;
    fin >> tests;

    while(tests--)
    {
        fin >> A >> B;
        fout << GetGCD(A, B) << '\n';
    }

    return 0;
}
