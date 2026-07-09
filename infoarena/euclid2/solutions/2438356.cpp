# include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc(int a, int b)
{
    if(!a)
        return b;
    return cmmdc(b%a,a);
}
int main()
{
    int a,b,n;
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
