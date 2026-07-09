#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
int euclid(int a,int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void citire()
{
    int x,y;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<'\n';
    }
}
int main()
{
    citire();
    return 0;
}
