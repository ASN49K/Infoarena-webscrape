#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    if(a<b) swap(a,b);
    int r=a%b;
    if(r==0) return b;
    else
    {
        int rant=b%r;
        while(rant!=0)
        {
            rant%=r;
        }
        return r;
    }
}
int a,b,n;
int main()
{
    fin >> n;
    for(int i=1;i<=n;i++)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
    }
    return 0;
}
