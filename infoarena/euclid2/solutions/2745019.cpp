#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, a, b;
    fin >> n;
    for (int i = 0; i < n; ++i)
    {
        fin >> a >> b;
        while (a && b)
        {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }
        fout << a + b << '\n'; // a + 0 sau b + 0;
    }
    fout.close();
    return 0;
}

/*
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int div(int a, int b)
{
    if (a == b)
        return a;
    else if (a > b)
        return div(a - b, b);
    else if (a < b)
        return div(a, b - a);
}
int main()
{
    int t, a, b;
    fin >> t;
    for (int i = 1; i <= t; ++i)
    {
        fin >> a >> b;
        fout << div(a, b) << " \n";
    }
    fout.close();
    return 0;
}
*/