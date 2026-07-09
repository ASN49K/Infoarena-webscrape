#include<fstream>
using namespace std;
int cmmdc(long a,long b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{
    int a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>a>>b;
    fout<<cmmdc(a,b);
}
