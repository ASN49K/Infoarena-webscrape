#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,x,y;

int euclid(int a,int b)
{
    if(b==0)
        return a;
    else return euclid(b,a%b);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<'\n';
    }
}
