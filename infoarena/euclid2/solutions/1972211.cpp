#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{   int a,b,r,i,n;
in>>n;
for(i=1;i<=3;i++)
{
    in>>a>>b;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    out<<b<<"\n";
}
}



