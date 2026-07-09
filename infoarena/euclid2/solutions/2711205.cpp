#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,T;
int main ()
{
    fin>>T;
    for(int i=0; i<T-1; i++)
    {
        fin>>a>>b;
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    fout<<a<< "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
