#include <iostream>
#include  <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, a, b;
void Euclid(int A, int B)
{
    int R;
    while(B)
    {
        R = A % B;
        A = B;
        B = R;
    }
    fout << A << '\n';
}

void Citire()
{
    fin >> T;
    for(int i = 1; i <= T; i++)
    {
        fin >> a >> b;
        Euclid(a,b);
    }
}
int main()
{
    Citire();
    return 0;
}
