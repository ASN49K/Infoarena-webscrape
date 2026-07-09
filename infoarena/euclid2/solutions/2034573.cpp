#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,i,a,b;
void cmmdc(int a,int b)
{
    if(b==0)fout<<a<<'\n';
    else cmmdc(b,a%b);
}
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
        cmmdc(a,b);
    }
    return 0;
}
