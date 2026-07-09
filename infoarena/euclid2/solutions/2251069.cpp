#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

long long CMMDC(long long a,long long b)
{
    if(b==0)return a;
    return CMMDC(b,a%b);
}


int main()
{

    long long n,a,b;

    fin >> n;

    for(int i=1;i<=n;++i)
    {
    fin >> a >> b;
    fout << CMMDC(a,b) << "\n";
    }




    return 0;
}
