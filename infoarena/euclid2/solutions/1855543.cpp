#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,t,i;
int cmmdc(int x, int y)
{
    int c;
    while (y) {
        c = x % y;
        x = y;
        y = c;
    }
    return x;
}
int main()
{
    fin>>t;
    for (i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
