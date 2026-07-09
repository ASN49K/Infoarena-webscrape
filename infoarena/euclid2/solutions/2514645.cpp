#include <fstream>

using namespace std;

const int TMAX = 100000;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T, a, b;
    fin >> T;

    for(int i = 0; i < T; i++)
    {
        fin >> a >> b;
        int r = a % b;
        while(r)
        {
            a = b;
            b = r;
            r = a % b;
        }
        fout << b << endl;
    }
    return 0;
}
