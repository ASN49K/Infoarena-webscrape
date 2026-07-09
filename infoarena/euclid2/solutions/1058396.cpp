#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int T,a,b,r;


int main()
{
    fin>>T;//citeste T
    for(;T;T--)
    {
        fin>>a>>b;//citeste a si b
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';//afiseaza a
    }
    return 0;
}

