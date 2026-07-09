#include <iostream>
#include <fstream>
using namespace std;

int Cmmdc(int a, int b)
{
    if (!b) return a;
    return Cmmdc(b, a % b);
}

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");

    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << Cmmdc(a, b) << endl;
    }

    fin.close();
    fout.close();

      return 0;
}
