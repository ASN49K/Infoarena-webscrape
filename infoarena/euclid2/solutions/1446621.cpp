#include <fstream>

using namespace std;
int c,a,b,n,i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
    c=0;
    fin>>a>>b;
    while (b)
        {
        c=a%b;
        a=b;
        b=c;
        }
    fout<<a<<'\n';
    }

    return 0;
}
