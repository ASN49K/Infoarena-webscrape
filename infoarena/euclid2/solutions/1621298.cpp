#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t,a,b;
    fin>>t;
    for(;t;--t)
    {
        fin>>a>>b;
        while(a%=b) a^=b^=a^=b;
        fout<<b<<'\n';
    }
    return 0;
}
