#include <fstream>
using namespace std;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    int t,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
