#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned long long a,b,T,x,y,d;
void Euclid(unsigned long long a,unsigned long long b, unsigned long long &x, unsigned long long &y, unsigned long long &d)
{
    if(b==0) {d=a;x=1;y=0;}
    else
    {
        unsigned long long x0,y0,r=a%b,c=a/b;
        Euclid(b,r,x0,y0,d);
        x=y0;
        y=x0-c*y0;
    }
}
int main()
{
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        Euclid(a,b,x,y,d);
        fout<<d<<'\n';
    }
    return 0;
}
