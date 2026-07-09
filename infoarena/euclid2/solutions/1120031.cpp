//euclid2

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int main()
{
    fin >> n;

    while(n>0)
    {
        fin >> a >> b;

        while(a!=b)
            if(a>b)
                a=a-b;
            else
                b=b-a;

        fout << a << "\n";

        n--;
    }

    fin.close();
    fout.close();

    return 0;
}
