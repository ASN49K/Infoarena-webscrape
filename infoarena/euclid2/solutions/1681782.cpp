#include    <iostream>
#include    <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;
int GCD(int A, int B)
{
    if(!B)
        return A;
    return GCD(B, A%B);
}
void Read()
{
    fin >> T;
    for(int i = 1; i <= T; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << GCD(a,b) << "\n";
    }
}

int main()
{
    Read();
    return 0;
}
