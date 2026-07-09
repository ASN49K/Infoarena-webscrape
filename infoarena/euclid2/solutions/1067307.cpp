#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t, a, b, r;

    fin>>t;
    bool ok = 1;
    int nr = 0;
    while(ok)
    {
        nr = nr + 1;
        fin>>a>>b;
        while(b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<endl;
        if(nr == t) ok = 0;
    }
}
