#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int nrPerechi, a, b;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> nrPerechi;

    for(int i = 0; i < nrPerechi; i++)
    {
        fin >> a >> b;

        int r = 1;

        while(b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    return 0;
}
