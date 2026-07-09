#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t;
    fin >> t;
    while (t--)
    {
        int n, x;
        fin >> n >> x;
        int s = x;
        for (int i = 2; i <= n; i++)
        {
            fin >> x;
            s = s ^ x;
        }
        if (s == 0)
            fout << "NU" << '\n';
        else
            fout << "DA" << '\n';
    }
    return 0;
}
