#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
   if (!b)
        return a;
    else
        return cmmdc(b,a%b);
}

int main()
{
    int n, e1, e2, i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>e1>>e2;
        fout<<cmmdc(e1, e2)<<"\n";
    }
    return 0;
}
