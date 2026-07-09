#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n;

int main()
{
    fin >> t;
    for (int i = 0; i < t; ++ i)
        {
         fin >> n;
         int sum = 0;
         for (int j = 0; j < n; ++ j)
            {
             int temp;
             fin >> temp;
             sum ^= temp;
            }
         fout << (sum > 0 ? "DA\n" : "NU\n");
        }
    fin.close();
    fout.close();
    return 0;
}
