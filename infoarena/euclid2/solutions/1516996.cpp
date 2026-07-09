#include <fstream>

using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int a,b,d;
int main()
{
    fin>>a;
    fin>>b;
    while(b)
    {d=a%b;
    a=b;
    b=d;
    }
    if(a==1)
        fout<<0;
    else
        fout<<a;
    return 0;
}
