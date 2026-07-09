#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, i, a, b, r;
int main()
{
    fin >> T;
    for(i = 1; i <= T; ++i)
    {
        fin >> a >> b;
        if(a < b)
            swap(a, b);
        while(b)
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
