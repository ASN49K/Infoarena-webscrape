#include <fstream>
using namespace std;

int cmmdc(int a, int b);

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T;
    fin >> T;

    int a, b;

    for(int i = 1; i <= T; ++i)
    {
        fin >> a >> b;

        fout << cmmdc(a, b) << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}

int cmmdc(int a, int b)
{
    int r;

    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}
