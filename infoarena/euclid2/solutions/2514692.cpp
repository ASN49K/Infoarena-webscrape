#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
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
    int T, a, b;
    fin >> T;

    for(int i = 0; i < T; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
