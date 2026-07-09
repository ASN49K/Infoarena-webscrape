#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    return cmmdc(b, a%b);
}
int main()
{
    int n,a,b;
    fin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
}
