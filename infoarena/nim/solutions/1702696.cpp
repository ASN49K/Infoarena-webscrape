#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t, n, a, sum;

int main()
{
    fin >> t;
    for (int i = 1; i <= t; i++)
    {
        fin >> n;
        sum = 0;
        for(int j = 1; j <= n; j++)
        {
            fin >> a;
            sum = sum ^ a;
        }

        if(sum != 0)fout << "DA\n";
        else fout << "NU\n";
    }
    return 0;
}
