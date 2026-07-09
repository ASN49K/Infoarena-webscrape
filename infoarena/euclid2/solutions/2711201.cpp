#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b;
int main ()
{
    fin>>a>>b;
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    fout<<a;
    fin.close();
    fout.close();
    return 0;
}
