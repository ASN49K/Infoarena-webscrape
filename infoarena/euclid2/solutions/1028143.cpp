#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b)
{
    if(!b)
        return a;
    return GCD(b,a%b);
}
int main()
{
    int T,a,b;
    fin>>T;
    while(T--)
    {
        fin>>a>>b;
        fout<<GCD(a,b)<<'\n';
    }
    return 0;
}

