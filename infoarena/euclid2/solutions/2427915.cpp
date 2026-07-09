#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, r;
    fin>>r;
    while(fin>>a>>b)
    {
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout<<a<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
