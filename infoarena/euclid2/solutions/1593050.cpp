#include <fstream>

using namespace std;

int Cmmdc(int a, int b)
{
    int r;
    while (b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int i , b, t, c;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin >> t;
    for (i = 1; i<=t; i++)
    {
        fin >> b >> c;
        fout << Cmmdc(b, c) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
