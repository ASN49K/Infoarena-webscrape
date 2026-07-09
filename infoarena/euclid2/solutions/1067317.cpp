#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t, a, b, r;

    fin>>t;
    while(t>0)
    {
        fin>>a>>b;
        while(b)
        {
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<endl;
        t--;
    }
    return 0;
}
