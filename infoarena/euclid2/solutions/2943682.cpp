#include <fstream>

using namespace std;

void euclidRecursiv(int a, int b, int &x)
{
    if(b == 0)
    {
        x = a;
        return;
    }

    euclidRecursiv(b, a % b, x);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t, i, a, b, cmmdc;

    fin >> t;

    for(i = 0; i < t; i++)
    {
        fin >> a >> b;

        euclidRecursiv(a, b, cmmdc);

        fout << cmmdc << '\n';
    }
    return 0;
}
