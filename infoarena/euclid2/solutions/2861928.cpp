#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int cmmdc(int a,int b)
{
    if (a==0)
        return b;
    else
        return cmmdc(b%a,a);

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
