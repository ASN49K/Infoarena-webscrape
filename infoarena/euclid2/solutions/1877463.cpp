#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    if(a%b == 0)
        return b;
    else
        return euclid(b,a%b);
}
int main()
{
    int t,a,b,d;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
