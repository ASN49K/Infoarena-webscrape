#include <fstream>

using namespace std;
ifstream fin("AE.in");
ofstream fout("AE.out");
int a,b,c,q;
int main()
{
    fin>>a>>b;

    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    fout<<a;
    return 0;
}
