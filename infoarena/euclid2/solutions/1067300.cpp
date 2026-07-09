#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t, a, b, r;

    fin>>t;
    int i = 1;
    while(i<=t)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<endl;
        i++;
    }
}
