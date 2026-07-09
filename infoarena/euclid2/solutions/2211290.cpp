#include <iostream>
#include <fstream>

using namespace std;

ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");

int n = 0, a, b;

int main ()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a>> b;
        int r = 0;
        while (b > 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a<< endl;
    }
    return 0;
}
