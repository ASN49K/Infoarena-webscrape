#include <fstream>
using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int euclid (int a,int b)
{
    int r;
    while(b>0)
    {
        r=a%b; //
        a=b; //
        b=r; //0
    }
    return a;
}

int main()
{
    int i,n,a,b;
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<endl;
    }
}

