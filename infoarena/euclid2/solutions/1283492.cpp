#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int T,N,M;
int euclid(int a,int b)
{
    if (b==0)
        return a;
    return euclid(b,a%b);
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
