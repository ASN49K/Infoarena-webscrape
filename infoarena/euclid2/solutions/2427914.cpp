#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int T, a, b, i = 1, r;
    fin>>T;
    while (i <= T)
    {
        fin>>a>>b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout<<a<<endl;
        i++;
    }
    fin.close();
    fout.close();
    return 0;
}
