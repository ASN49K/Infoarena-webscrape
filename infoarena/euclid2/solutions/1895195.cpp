#include <fstream>

using namespace std;

int cmmdc (int a ,int b)
{
    int r=a%b;
    while (a!=b)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return a;
}

int n;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>n;
    for (int i=1;i<=n;++i)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
}
