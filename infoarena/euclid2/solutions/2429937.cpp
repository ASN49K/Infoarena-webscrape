#include <fstream>

using namespace std;

int main()
{
    int n, i, j, a, b, c;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> n;

    for(i = 0; i < n; i++)
    {
        fin >> a >> b;

        while(b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }

        fout << a << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}
