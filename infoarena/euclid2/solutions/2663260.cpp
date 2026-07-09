#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
unsigned int a,b;
unsigned int cmmdc(unsigned int a,unsigned int b)
{
    if (!b)
        return a;
    else
        return cmmdc(b,a%b);


}



int main()
{
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
