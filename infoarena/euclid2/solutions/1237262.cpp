#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,c,q;
int main()
{
    fin>>a>>b;
    if(a<<b)
    c=1;
    while(c!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    fout<<a;
    return 0;
}
