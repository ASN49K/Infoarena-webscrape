#include <fstream>

using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int CMMDC(int a,int b)
{
    while (b!=0)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int N;
int main()
{
    fin>>N;
    for (int i=1; i<=N; i++)
    {
        int x,y;
        fin>>x>>y;
        fout<<CMMDC(x,y)<<"\n";
    }
    return 0;
}
