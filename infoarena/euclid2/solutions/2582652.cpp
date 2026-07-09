#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int a,b,n;
int main()
{
    fin >> n;
    for(int i=1;i<=n;i++)
    {
        fin >> a >> b;
        fout << cmmdc(min(a,b),max(a,b)) << "\n";
    }
    return 0;
}
