#include <fstream>

using namespace std;

int main()
{
    int n, a, b, r, i;
    ifstream fin("euclid2.in");
    fin >> n;
    ofstream fout("euclid2.out");
    for(i = 1; i <= n; i++)
    {
        fin >> a >> b;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
