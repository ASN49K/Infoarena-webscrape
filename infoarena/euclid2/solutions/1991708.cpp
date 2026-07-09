#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int T, a, b;

    fin >> T;

    for(int i = 0; i < T; ++i)
    {
        fin >> a >> b;
        while(b > 0)
        {
            int m = a % b;
            a = b;
            b = m;
        }
        fout << a;
    }



    return 0;
}
