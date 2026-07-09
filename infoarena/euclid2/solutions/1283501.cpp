#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int T,N,M;
int euclid(int a,int b)
{
    int sol;
    if (b==0)
        return a;
    sol=euclid(b,a%b);
    return sol;
}
int main(void)
{
    fin>>T;
    while(T--)
    {
        fin>>N>>M;
        fout<<euclid(N,M)<<endl;
    }
    return 0;
}
