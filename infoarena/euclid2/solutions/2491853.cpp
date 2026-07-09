#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");


int main()
{
    int n, a, b;
    fin >> n;
    for(int i = 0; i < n; ++i)
    {
        fin >> a >> b;
        while(b > 0)
        {
            int m = a % b;
            a = b;
            b = m;
        }
        fout << a << '\n';
    }
}
