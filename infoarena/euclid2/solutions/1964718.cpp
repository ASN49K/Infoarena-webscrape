#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    if(a==0)
        return b;
    else
        return euclid(b%a,a);
}
int main()
{
    int t,a,b;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
