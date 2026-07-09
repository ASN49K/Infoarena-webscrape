#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a, b;
    int t, x;

    fin >> t;

    for(int i=0; i<t; i++)
    {
        fin >> a >> b;

        while(b!=0)
        {
            x = b;
            b = a%b;
            a = x;
        }

        fout << a << endl;
    }
    return 0;
}
