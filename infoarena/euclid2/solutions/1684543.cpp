#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int T,a,b;

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a%b);
} 

int main()
{
    cin>>T;
    for(T;T;T--)
    {
       cin>>a>>b;
       cout<<gcd(a,b)<<endl
       ;
    }
return 0;
}
