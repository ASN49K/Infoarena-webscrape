#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    int d=a,i=b,r;
    do {
        r=d%i;
        d=i;
        i=r;
        }
        while (r);
    return d;

}
int main()
{
    int n, a, b, i;
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin>>n;
    for(i=1; i<=n; i++)
        {
            cin>>a>>b;
           cout<<cmmdc(a,b)<<"\n";
        }

}
