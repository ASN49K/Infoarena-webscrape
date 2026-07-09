#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long n, x, y, r;
int main()
{
    fin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        fin>>x>>y;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    return 0;
}
