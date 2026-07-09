#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t;
    fin >> t;
    while(t--)
    {
        int n;
        fin >> n;
        long long x, xr = 0;
        for(int i = 0; i < n; i++)
        {
            fin >> x;
            xr ^= x;
        }
        if(xr == 0)
        {
            fout << "NU\n";
        }
        else
        {
            fout << "DA\n";
        }
    }
    return 0;
}
