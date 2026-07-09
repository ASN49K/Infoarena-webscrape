#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,c,n,i;

int main()
{
    fin>>n;
    for (i=1;i<=n;i++)
    {
        fin>>a>>b;
        while (b) {
            c = a % b;
            a = b;
            b = c;
        }
        fout<<a<<'\n';
    }
    return 0;
}
