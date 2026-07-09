#include <fstream>
using namespace std;
int n, m, x, nr, d, b, a, r, i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
        fin>>n;
        for(i=1;i<=n;i++)
        {
            fin>>a>>b;
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            fout<<a<<endl;
        }
    return 0;
}
