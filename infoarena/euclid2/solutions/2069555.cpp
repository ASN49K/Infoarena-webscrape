#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int nrPerechi, a, b, i, r=1;

int main()
{
    fin >> nrPerechi;
    for (i = 1; i <= nrPerechi; i++)
    {   r = 1;
        fin >> a >> b;
        while(r)
        {
            r = a % b;
            a = b;
            b = r;

        }
        fout<< a <<"\n";
    }
    return 0;
}

/*#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int nrPerechi, a, b, r = 1;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> nrPerechi;

    for(int i = 1; i <= nrPerechi; i++)
    {
        r = 1;

        fin >> a >> b;

        while(r)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    return 0;
}*/
