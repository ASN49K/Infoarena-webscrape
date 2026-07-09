#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, r;
int main()
{
    int t;
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
        t--;
    }
    fin.close();
    fout.close();
    return 0;
}
