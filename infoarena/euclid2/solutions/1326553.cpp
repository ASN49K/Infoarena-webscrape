#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b)
    {
        return a;
    }
    else
    {
        cmmdc(b,a%b);
    }
}
int main()
{
    int n; int i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    fin.close();
    fout.close();

    return 0;
}
