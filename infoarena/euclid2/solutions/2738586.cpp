#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int a, b, T;

int cmmdc(int A, int B)
{
    if(!B)
        return A;
    return cmmdc(B, A % B);
}

int main()
{
    fin >> T;
    for (int i = 0; i < T; ++i)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';

    }

    return 0;
}
