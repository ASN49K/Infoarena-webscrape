#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int Alg_Euclid(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int N,a,b;
    f>>N;
    for(int i=1;i<=N;i++)
    {
        f>>a>>b;
        g<<Alg_Euclid(a,b)<<'\n';
    }
    return 0;
}
