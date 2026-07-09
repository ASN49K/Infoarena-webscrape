#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{

    int t;
    fin>>t;
    for(int i = 0,x,y; i<t; i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
