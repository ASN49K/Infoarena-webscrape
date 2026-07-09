#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t, a,b,cmmdc(int,int);
int main()
{
    cin>>t;
    for (;t;t--)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
int cmmdc(int a, int b)
{
    if (b==0) return a;
    return cmmdc(b, a%b);
}
