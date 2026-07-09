#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t, a, b, i, r;
int main()
{
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }
    return 0;
}
