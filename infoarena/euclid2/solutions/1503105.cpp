#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,a,b,i,r;
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>a;
        in>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        out<<b<<"\n";
    }
    return 0;
}
