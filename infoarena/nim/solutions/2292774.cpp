#include<fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n, sol, i, value, t, j;

int main()
{
    fin >> t;
    for (i = 1; i <= t; i++)
    {
        fin >> n;

        sol = 0;

        for (j = 1; j <= n; j++)
        {
            fin >> value;
            sol = sol ^ value;
        }

        if (sol == 0)
        {
            fout << "NU" << "\n";
        }
        else
        {
            fout << "DA" << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
