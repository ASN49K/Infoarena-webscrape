#include <fstream>
using namespace std;
fstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n , m, x;
    fin >> x;
    for(int i = 1; i <= x; i++)
    {
        fin>> n >> m;
        while(m != 0)
        {
            int r = n % m;
            n = m;
            m = r;
        }
        fout<< n << "\n";
    }
    return 0;
}
