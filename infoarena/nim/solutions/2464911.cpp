#include <fstream>

using namespace std;

int main()
{
    int t, n, i, j, a, sol;

    ifstream fin("nim.in");
    ofstream fout("nim.out");

    fin >> t;

    for(i = 0; i < t; i++)
    {
        fin >> n;

        sol = 0;
        for(j = 0; j < n; j++)
        {
            fin >> a;

            sol ^= a;
        }

        if(sol != 0)fout << "DA" << '\n';
        else fout << "NU" << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}
