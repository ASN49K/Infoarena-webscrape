#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int t, a, b;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<"\n";
    }
}
