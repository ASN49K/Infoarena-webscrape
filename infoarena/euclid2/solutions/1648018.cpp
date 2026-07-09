#include <fstream>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int euclid(int a, int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int t, a, b;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<euclid(a, b)<<'\n';
    }
    return 0;
}
