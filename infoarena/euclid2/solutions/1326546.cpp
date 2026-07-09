#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return cmmdc(b,a%b);
    }
}
int main()
{
    int t; int a,b;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }

    return 0;
}
