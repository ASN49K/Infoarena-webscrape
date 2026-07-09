#include <iostream>
#include <fstream>

using namespace std;

std::ifstream fin ("euclid2.in");
std::ofstream fout ("euclid2.out");

int main()
{
    int n,t,a,b;
    fin >> n ;
    for (int i=0;i<n;++i)
    {
        fin >> a >> b ;
        while (b!=0)
        {
            t = b;
            b = a % b;
            a = t;
        }
        fout << a << "\n" ;
    }
}
