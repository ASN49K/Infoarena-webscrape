#include <iostream>
#include <fstream>

std :: ifstream fin ("euclid2.in");
std :: ofstream fout ("euclid2.out");

int main()
{
    long long int T, a, b;
    fin >> T;
    for (int i = 0; i < T; i ++)
    {
        fin >> a >> b;
        while (a != 0)
        {
            int r = b % a;
            b = a;
            a = r;
        }
        fout << b << std :: endl;
    }

}
