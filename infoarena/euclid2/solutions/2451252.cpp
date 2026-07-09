#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    unsigned long long int i,T,a,b,r;
    fin >> T;
    for (i=1;i<=T;i++)
    {
        fin >> a >> b;
        if (b>a)
            r=a,a=b,b=r;
        r=a%b;
        while (r)
            a=b,b=r,r=a%b;
        fout << b << '\n';
    }
    return 0;
}
