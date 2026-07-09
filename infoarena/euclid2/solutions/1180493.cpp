#include <fstream>

using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

int main()
{
    int a, b, r;
    fin>>a>>b;
    while(a%b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    if(b!=1) fout<<b;
    else fout<<0;
    return 0;
}
