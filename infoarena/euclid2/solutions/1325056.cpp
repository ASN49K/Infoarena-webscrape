/*
    Rescriere OLI 2015
    Start: 10:45
*/

#include    <iostream>
#include    <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int A, int B)
{
    if(!B)
        return A;
    return GCD(B, A%B);
}

void Read()
{
    int N, x, y;
    fin >> N;
    for(int i = 1; i <= N; i++)
    {
        fin >> x >> y;
        fout << GCD(x, y) << "\n";
    }
}

int main()
{
    Read();
    return 0;
}
