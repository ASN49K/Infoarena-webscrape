#include <fstream>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int main()
{   int n,a,b,r;
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>a>>b;
         while(a != b)
        if(a > b)
            a -= b;
        else
            b -= a;
        fout<<a<<'\n';
    }
    return 0;
}
