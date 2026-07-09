#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T, i;
    long a, b, c;

    fin >> T;

    for(i=1 ; i<=T ; ++i)
    {
        fin >> a >> b;

        while(b)
        {
            c = a % b;
            a = b;
            b = c;
        }

        fout << a << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
