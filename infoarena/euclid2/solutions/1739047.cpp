#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid2 (int a, int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    int T, a, b;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        fout<<euclid2(a,b)<<'\n';
    }
    return 0;
}
