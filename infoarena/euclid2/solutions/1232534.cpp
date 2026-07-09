#include <fstream>
#include <iostream>
using namespace std;

int Cmmdc(int a, int b)
{
    int r;
    while(b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int T, a, b, result;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> T;
    while(T--)
    {
        fin >> a >> b;
        result = Cmmdc(a, b);
        fout << result << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
