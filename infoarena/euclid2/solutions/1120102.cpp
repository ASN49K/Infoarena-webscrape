//euclid2

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b, t;

int main()
{
    fin >> n;

    while(n>0)
    {
        fin >> a >> b;

        while(b!=0)
        {
            t=b;
            b=a%b;
            a=t;
        }

        fout << a << "\n";

        n--;
    }

    fin.close();
    fout.close();

    return 0;
}
