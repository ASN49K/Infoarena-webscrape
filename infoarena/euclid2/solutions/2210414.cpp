#include <fstream>
#include <iostream>

using namespace std;


int alg (int a, int b)
{
    int r = 0;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
};

int main()
{
    int t, a, b;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        fin >> a >> b;
        fout << alg(a, b) << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
