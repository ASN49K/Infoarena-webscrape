#include <iostream>
#include <fstream>

using namespace std;

int Euclid(int a, int b)
{
    if (a < b)
    {
        int aux = a;
        a = b;
        b = aux;
    }
    if (b == 0)
    {
        return a;
    }
    return Euclid(a % b, b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin >> T;
    for (int i = 1; i <= T; ++i)
    {
        int a, b;
        fin >> a >> b;
        fout << Euclid(a, b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
