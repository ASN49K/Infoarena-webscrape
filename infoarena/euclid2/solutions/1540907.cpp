#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,t,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++){
    fin>>a>>b;
    while(a!=0)
    {
        r=b%a;
        b=a;
        a=r;
    }
    fout<<b<<"/n";}
    return 0;
}
