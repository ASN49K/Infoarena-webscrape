#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a,int b)
{
    if(!b)
        return a;
    return euclid(b,a%b);
}
int a,b,T;

int main()
{
    fin>>T;
    while(T--)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
