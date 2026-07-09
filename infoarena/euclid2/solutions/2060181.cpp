#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int n,a,b;

int gdc(int a, int b)
{
    if(!b)
        return a;
    return gdc(b,a%b);
}

int main()
{
    cin>>n;
    for(; n; --n)
    {
        cin>>a>>b;
        cout<<gdc(a,b)<<endl;
    }
    return 0;
}
