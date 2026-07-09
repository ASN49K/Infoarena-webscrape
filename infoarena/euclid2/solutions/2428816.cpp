#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int x, nr1, nr2, rest;
    fin>>x;
    for(int i=1; i<=x; i++)
    {
        fin>>nr1>>nr2;
        while(nr2!=0)
        {
            rest = nr1%nr2;
            nr1 = nr2;
            nr2 = rest;
        }
        fout<<nr1<<"\n";
    }
    return 0;
}
