#include <fstream>

using namespace std;
ifstream fin("AE.in");
ofstream fout("AE.out");
int a,b,c,q;
int main()
{
    fin>>a>>b;
        if(a<<b)
    {
        c=a;
        a=b;
        b=c;
    }
    while(a%b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    fout<<b;
    return 0;
}
